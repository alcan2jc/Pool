#pragma once

#include <raylib.h>
#include <stdbool.h>
#include "ball.h"

typedef struct Stick {
	Vector2 pos;
	float rotation;
	Rectangle rec;
	Vector2 origin;
}Stick;

void init_stick(Stick*, Ball*);
void update_stick(Stick*, Ball*);
void update_rotation(Stick*);
void draw_stick(Stick*);