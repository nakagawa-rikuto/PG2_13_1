#pragma once
#include "Vector2.h"
#include "Novice.h"

class Bullet {

public:

	void Init(Vector2 pos);
	void Update();
	void Draw();
	Vector2 GetPos() { return pos_; }
	float GetRadius() { return radius_; }
	Bullet();

private:

	Vector2 pos_;

	float radius_;

	float speed_;

	bool isShot_;
	bool preIsShot_;

};

