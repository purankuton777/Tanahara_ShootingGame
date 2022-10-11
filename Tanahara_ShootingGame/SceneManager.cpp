#include "SceneManager.h"
// �����o�ϐ��̒l������������̂��A�b�v�f�[�g�֐�
AbstractScene* SceneManager::Update()
{
    // ���݃V�[���̃A�b�v�f�[�g�����s
    AbstractScene* p = mScene->Update();
    // ���̃V�[�������݃V�[���ƈႤ�ꍇ�؂�ւ���
    if (p != mScene) {
        delete mScene;
        mScene = p;
    }
    return p;
}
// �`�揈���݂̂��s���֐�
void SceneManager::Draw() const {
    // ���݃V�[���̕`��֐������s
    mScene->Draw();
}