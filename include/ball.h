#pragma once
#include <stdbool.h>
#include <raylib.h>

typedef struct Ball {

	Vector2 pos;
	bool cue;
	float radius;
	Color color;
	Vector2 vel;
	Vector2 acc;

} Ball;

void init_ball(Ball*, Vector2, bool);
void draw_ball(Ball*);
//void hit(Ball*, Stick*);
