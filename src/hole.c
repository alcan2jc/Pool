#include "include.h"

void init_hole (Hole* h, Vector2 pos) {

	h->pos = pos;
	h->radius = 30;
}

void draw_hole(Hole* h) {
	DrawCircle(h->pos.x, h->pos.y, h->radius, BLACK);
}