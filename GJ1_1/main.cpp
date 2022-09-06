#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR IpCmdLine, int nCmdShow)
{
	const int WIN_WIDTH = 1300;
	const int WIN_HEIGHT = 800;

	ChangeWindowMode(true);							// ウインドウモードにする
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);	// 画面モードのセット
	SetBackgroundColor(0, 0, 0);					// 背景色 RGB
	if (DxLib_Init() == -1) return -1;				// DxLib 初期化設定
	SetDrawScreen(DX_SCREEN_BACK);					// 描画先画面を裏画面にセット

	char keys[256] = { 0 };							// 最新のキーボード情報用
	char oldkeys[256] = { 0 };						// 1ループ(フレーム)前のキーボード情報

	// ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		for (int i = 0; i < 256; i++) {
			oldkeys[i] = keys[i];
		}

		GetHitKeyStateAll(keys);					// 最新のキーボード情報を取得

		ClearDrawScreen();							// 画面を消去

		// 更新 ----------------------------

		// 描画 ----------------------------

#pragma region 画面サイズ
		DrawLine(350, 0, 350, 800, GetColor(255, 255, 255));
		DrawLine(950, 0, 950, 800, GetColor(255, 255, 255));
#pragma endregion

		// フリップする
		ScreenFlip();
	}
	DxLib_End();	// DxLib 終了処理
	return 0;	// ソフトの終了
}