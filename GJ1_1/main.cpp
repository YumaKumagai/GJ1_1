#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR IpCmdLine, int nCmdShow)
{
	const int WIN_WIDTH = 1300;
	const int WIN_HEIGHT = 800;

	ChangeWindowMode(true);							// �E�C���h�E���[�h�ɂ���
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);	// ��ʃ��[�h�̃Z�b�g
	SetBackgroundColor(0, 0, 0);					// �w�i�F RGB
	if (DxLib_Init() == -1) return -1;				// DxLib �������ݒ�
	SetDrawScreen(DX_SCREEN_BACK);					// �`����ʂ𗠉�ʂɃZ�b�g

	char keys[256] = { 0 };							// �ŐV�̃L�[�{�[�h���p
	char oldkeys[256] = { 0 };						// 1���[�v(�t���[��)�O�̃L�[�{�[�h���

	// �Q�[�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		for (int i = 0; i < 256; i++) {
			oldkeys[i] = keys[i];
		}

		GetHitKeyStateAll(keys);					// �ŐV�̃L�[�{�[�h�����擾

		ClearDrawScreen();							// ��ʂ�����

		// �X�V ----------------------------

		// �`�� ----------------------------

#pragma region ��ʃT�C�Y
		DrawLine(350, 0, 350, 800, GetColor(255, 255, 255));
		DrawLine(950, 0, 950, 800, GetColor(255, 255, 255));
#pragma endregion

		// �t���b�v����
		ScreenFlip();
	}
	DxLib_End();	// DxLib �I������
	return 0;	// �\�t�g�̏I��
}