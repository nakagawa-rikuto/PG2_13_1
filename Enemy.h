#pragma once
#include "Vector2.h"
#include "Novice.h"

class Enemy {
public:

	void Update();
	void Draw();

	Vector2 GetPos() { return pos_; }
	float GetRadius() { return radius_; }
	
	static bool isAlive_;

	Enemy(float PosX,float PosY);
	~Enemy() {};

private:

	Vector2 pos_;

	float radius_;
	float speed_;

	float coolTime_;
};

