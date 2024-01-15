#include "Bullet.h"

class Player {
public:

	void Update();
	void Draw();
	Vector2 GetBulletPos() { return bullet_->GetPos(); }
	float GetBulletRadius() { return bullet_->GetRadius(); }
	Player();

private:

	Bullet* bullet_;

	Vector2 pos_;

	Vector2 bulletPos_;

	float radius_;

	float speed_;

	bool isShot_;

	void Move();

};

