#include "Bullet.h"

Bullet::Bullet() {

	pos_ = { -200.0f,-200.0f };

	radius_ = 25.0f;

	speed_ = 6.0f;

	isShot_ = false;
	preIsShot_ = isShot_;
}


void Bullet::Init(Vector2 pos){

	pos_ = { pos.x, pos.y };

}

void Bullet::Update() {

	pos_.y -= speed_;

}

void Bullet::Draw() {

	Novice::DrawEllipse(
		static_cast<int>(pos_.x), static_cast<int>(pos_.y),
		static_cast<int>(radius_), static_cast<int>(radius_),
		0.0f, BLACK, kFillModeSolid);
}

