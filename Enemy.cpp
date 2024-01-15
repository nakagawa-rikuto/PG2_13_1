#include "Enemy.h"

Enemy::Enemy(float PosX,float PosY) {

	pos_ = { PosX,PosY };

	radius_ = 15.0f;

	speed_ = 5.0f;

	coolTime_ = 120.0f;

}

void Enemy::Update(){

	if (isAlive_) {

		pos_.x += speed_;

		if (pos_.x <= 0.0f + radius_ || pos_.x >= 1280.0f - radius_) {

			speed_ *= -1.0f;
		}

	} else {

		coolTime_ -= 1.0f;

		if(coolTime_ <= 0.0f){

			isAlive_ = true;
			coolTime_ = 120.0f;
		}
	}
}

void Enemy::Draw(){

	Novice::ScreenPrintf(10, 150, "%d" ,int(coolTime_));

	if (isAlive_) {

		Novice::DrawEllipse(
			static_cast<int>(pos_.x), static_cast<int>(pos_.y),
			static_cast<int>(radius_), static_cast<int>(radius_),
			0.0f, RED, kFillModeSolid);
	}
}


