#include "Enemy.h"
#include "Player.h"
#include <math.h>

const char kWindowTitle[] = "LC1B_17_ナカガワ_リクト_タイトル";

bool Enemy::isAlive_ = true;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	//Enemy
	Enemy* enemy[2];

	enemy[0] = new Enemy(100.0f,200.0f);
	enemy[1] = new Enemy(400.0f,300.0f);

	//Player
	Player* player = new Player();

	//Collision
	Vector2 distance = { 0.0f,0.0f };
	float distanceSum = 0.0f;
	float radiusSum = 0.0f;

	bool isHit = false;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player->Update();

		for (int num = 0; num < 2; num++) {

			enemy[num]->Update();

			//当たり判定
			distance.x = enemy[num]->GetPos().x - player->GetBulletPos().x;
			distance.y = enemy[num]->GetPos().y - player->GetBulletPos().y;

			distanceSum = sqrtf(distance.x * distance.x + distance.y * distance.y);

			radiusSum = enemy[num]->GetRadius() +player->GetBulletRadius();

			if (radiusSum >= distanceSum) {

				isHit = true;
			}

			if (isHit) {

				enemy[num]->isAlive_ = false;
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::ScreenPrintf(10, 10, "%d", isHit);
		Novice::ScreenPrintf(10, 40, "%d", int(distanceSum));
		Novice::ScreenPrintf(10, 70, "%d", int(radiusSum));
		Novice::ScreenPrintf(10, 100, "%d", int(player->GetBulletPos().x));
		Novice::ScreenPrintf(10, 130, "%d", int(player->GetBulletPos().y));


		player->Draw();

		for (int num = 0; num < 2; num++) {

			enemy[num]->Draw();
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete enemy[0];
	delete enemy[1];
	delete player;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
