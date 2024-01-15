#include "Player.h"

Player::Player() {

	bullet_ = new Bullet();

	pos_ = { 640.0f,360.0f };

	bulletPos_ = bullet_->GetPos();

	radius_ = 20.0f;

	speed_ = 7.0f;

	isShot_ = false;
}


void Player::Move() {

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	if (keys[DIK_A]) {

		pos_.x -= speed_;
	}

	if (keys[DIK_D]) {

		pos_.x += speed_;
	}

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

		if (!isShot_) {
			isShot_ = true;
			bullet_->Init(pos_);
		}
	}
}


void Player::Update(){

	Move();

	bulletPos_ = bullet_->GetPos();

	if (isShot_) {

		bullet_->Update();
	}

	if (bulletPos_.y < -bullet_->GetRadius()) {

		isShot_ = false;
	}
}

void Player::Draw(){

	Novice::DrawEllipse(
		static_cast<int>(pos_.x), static_cast<int>(pos_.y),
		static_cast<int>(radius_), static_cast<int>(radius_),
		0.0f, WHITE, kFillModeSolid);

	if (isShot_) {
		bullet_->Draw();
	}
}


