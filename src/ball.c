#include "include.h"

void init_ball(Ball* b, Vector2 pos, bool cue) {

	b->pos = pos;
	b->cue = cue;
	b->color = WHITE;
	b->vel.x = 0;
	b->vel.y = 0;
	b->acc.x = 0;
	b->acc.y = 0;
}

void draw_ball(Ball* b) {
	Color color = RED;
	if (b->cue) {
		color = WHITE;
	} else {
		color = BLUE;
	}

	DrawCircle(b->pos.x, b->pos.y, ball_radius, color);
}

// void hit(Ball* b, Stick* s) {
// 	b->pos.x = b->pos.x * cos(s->rotation);
// 	b->pos.y = b->pos.y * sin(s->rotation);
// } 

