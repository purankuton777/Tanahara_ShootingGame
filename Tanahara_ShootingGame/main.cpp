#inclde"dxlib"

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	// �^�C�g���� test �ɕύX
	SetMainWindowText("�u���b�N����");

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

	if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

	//�^�C�g���摜�f�[�^�̓ǂݍ���
	if ((g_TitleImage = LoadGraph("images/Title.png")) == -1) return -1;
	//�����L���O�摜�f�[�^�̓ǂݍ���
	if ((g_RankingImage = LoadGraph("images/Ranking.bmp")) == -1) return -1;
	//�G���h�摜�f�[�^�̓ǂݍ���
	if ((g_EndImage = LoadGraph("images/End.bmp")) == -1) return -1;
	//�u���b�N�摜�f�[�^�̓ǂݍ���
	if (LoadDivGraph("images/Block.bmp", 8, 8, 1, 40, 8, g_BlockImage) == -1) return -1;

	if (ranking.ReadRanking() == -1)  return  -1;    //�����L���O�f�[�^�̓ǂݍ���

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

	SetFontSize(20);		// �����T�C�Y��ݒ�

	SceneManager sceneMng((AbstractScene*)new Title());

	// �Q�[�����[�v
	while (ProcessMessage() == 0 && g_GameState != GAME_STATE::EXIT) {


		ClearDrawScreen();		// ��ʂ̏�����

		sceneMng.Draw();

		ScreenFlip();

	}



		switch (g_GameState) {
		case GAME_STATE::GAME_TITLE:
			DrawGameTitle();	   //�Q�[���^�C�g������
			break;
		case GAME_STATE::GAME_INIT:
			GameInit();		       //�Q�[����������
			break;
		case GAME_STATE::DRAW_RANKING:
			DrawRanking();	       //�����L���O�`�揈��
			break;
		case GAME_STATE::DRAW_END:
			DrawEnd();		      //�G���h��ʕ`�揈��
			break;
		case GAME_STATE::GAME_MAIN:
			GameMain();		      //�Q�[�����C������
			break;
		case GAME_STATE::DRAW_GAME_OVER:
			DrawGameOver();       //�Q�[���I�[�o�[�`�揈��
			break;
		case GAME_STATE::DRAW_GAME_CLEAR:
			DrawGameClear();      //�Q�[���N���A�`�揈��
			break;
		case GAME_STATE::INPUT_RANKING:
			InputRanking();       //�����L���O���͏���
			break;
		}

		ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f

	}

	DxLib_End();	// DX���C�u�����g�p�̏I������

	return 0;	// �\�t�g�̏I��
}
