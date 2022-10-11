#inclde"dxlib"

/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	// タイトルを test に変更
	SetMainWindowText("ブロック崩し");

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動

	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

	//タイトル画像データの読み込み
	if ((g_TitleImage = LoadGraph("images/Title.png")) == -1) return -1;
	//ランキング画像データの読み込み
	if ((g_RankingImage = LoadGraph("images/Ranking.bmp")) == -1) return -1;
	//エンド画像データの読み込み
	if ((g_EndImage = LoadGraph("images/End.bmp")) == -1) return -1;
	//ブロック画像データの読み込み
	if (LoadDivGraph("images/Block.bmp", 8, 8, 1, 40, 8, g_BlockImage) == -1) return -1;

	if (ranking.ReadRanking() == -1)  return  -1;    //ランキングデータの読み込み

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	SetFontSize(20);		// 文字サイズを設定

	SceneManager sceneMng((AbstractScene*)new Title());

	// ゲームループ
	while (ProcessMessage() == 0 && g_GameState != GAME_STATE::EXIT) {


		ClearDrawScreen();		// 画面の初期化

		sceneMng.Draw();

		ScreenFlip();

	}



		switch (g_GameState) {
		case GAME_STATE::GAME_TITLE:
			DrawGameTitle();	   //ゲームタイトル処理
			break;
		case GAME_STATE::GAME_INIT:
			GameInit();		       //ゲーム初期処理
			break;
		case GAME_STATE::DRAW_RANKING:
			DrawRanking();	       //ランキング描画処理
			break;
		case GAME_STATE::DRAW_END:
			DrawEnd();		      //エンド画面描画処理
			break;
		case GAME_STATE::GAME_MAIN:
			GameMain();		      //ゲームメイン処理
			break;
		case GAME_STATE::DRAW_GAME_OVER:
			DrawGameOver();       //ゲームオーバー描画処理
			break;
		case GAME_STATE::DRAW_GAME_CLEAR:
			DrawGameClear();      //ゲームクリア描画処理
			break;
		case GAME_STATE::INPUT_RANKING:
			InputRanking();       //ランキング入力処理
			break;
		}

		ScreenFlip();			// 裏画面の内容を表画面に反映

	}

	DxLib_End();	// DXライブラリ使用の終了処理

	return 0;	// ソフトの終了
}
