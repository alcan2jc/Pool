#include "include.h"

Vector2 addvec(Vector2 v1, float add) {
	Vector2 v;
	v.x = v1.x + add;
	v.y = v1.y + add;

	return v;
}

Vector2 subvec(Vector2 v1, float sub) {
	Vector2 v;
	v.x = v1.x - sub;
	v.y = v1.y - sub;

	return v;
}

Vector2 mulvec(Vector2 v1, float mul) {
	Vector2 v;
	v.x = v1.x * mul;
	v.y = v1.y * mul;

	return v;
}