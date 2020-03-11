#pragma once
#include <raylib.h>
#include <stdbool.h>
#include "Vector2.h"

typedef struct Hole {

	Vector2 pos;
	float radius;

}Hole;

void init_hole(Hole*, Vector2);
void draw_hole(Hole*);