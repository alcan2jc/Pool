#include "include.h"

#define printvec(v) printf("x: %f, y: %f\n", v.x, v.y)

void init_stick(Stick* s, Ball* b) {
	s->pos = b->pos;
	s->rotation = 90; 

	s->rec.x = s->pos.x; 
	s->rec.y = s->pos.y; 
	s->rec.width = 500; //stickwidth
	s->rec.height = 8; //stickheight

	s->origin.x = -ball_radius - 30;
	s->origin.y = s->rec.height / 2.0;
	
}

//this function draws the stick
void draw_stick(Stick* s) {

	//DEBUG_________________________________________________________________________________

	//printf("stick: (%f, %f)\n", s->pos.x, s->pos.y);
	//printf("origin: (%f, %f)\n", s->origin.x, s->origin.y);
	//printf("tip: (%f, %f)\n", s->pos.x - (-ball_radius - 30), s->pos.y - (s->rec.height / 2.0));
	//DrawCircle(s->pos.x - (s->origin.x * s->rotation), s->pos.y - (s->origin.y * s->rotation), 5, RED);  

	//___________________________________________________________________________________________________

	DrawRectanglePro(s->rec, s->origin, s->rotation, BROWN);
}

//function handles the pull of the stick, and the rotation update. 
void update_stick(Stick* s, Ball* b) {
	static Vector2 old_origin;
	bool sticktoofar = (fabs(s->origin.x) > 100) || (fabs(s->origin.y) > 100);

	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
		if (!sticktoofar) {
			s->origin = mulvec(s->origin, 1.1);
		}
	} else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
		s->origin.x = -ball_radius; //ball radius
		s->origin.y = s->rec.height / 2.0;

		//hit(b, s)
		b->pos.x += (s->rotation * 0.5);
		b->pos.y += (s->rotation * 0.5);

	} else {
		old_origin = s->origin;
	}

	update_rotation(s);
}

//
void update_rotation(Stick* s) {
	float opp = s->pos.y - GetMouseY();
	float adj = s->pos.x - GetMouseX();

	s->rotation = atan2(opp , adj) * RAD2DEG;
}