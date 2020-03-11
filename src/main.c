#include "include.h"

static int screenWidth = MONITOR_WIDTH * .9;
static int screenHeight = MONITOR_HEIGHT * .9;

Vector2 init_vector(float x, float y) {
    Vector2 v;
    v.x = x;
    v.y = y;
    return v;
}

int main () {

	// Initialization
    //--------------------------------------------------------------------------------------

	//Make the table dimensions
	float table_width = 500;
    float borderlength = 60;
	float tablex1 = screenWidth - (screenWidth * .65);
	float tablex2 = tablex1 + table_width;
	float tabley1 = borderlength;
	float tabley2 = screenHeight - borderlength;

	//cueball init__________________________________________________________________________________________
	Ball cueball;
	Ball b;
	bool cue = true;
    Vector2 cuepos;
    cuepos.x = tablex1 + (table_width * 0.5);
    cuepos.y = (tabley2) * .75;
    Vector2 ballpos;
    ballpos.x = tablex1 + (table_width * 0.5);
    ballpos.y = (tabley2) * .25;
	init_ball(&cueball, cuepos, cue); //cue ball
	init_ball(&b, ballpos, !cue); //random blue ball
	//_________________________________________________________________________________________________________

	//Hole init_______________________________________________________________________________________
	Hole topleft;
	Hole topright;
	Hole midleft;
	Hole midright;
	Hole botleft;
	Hole botright;

	float hole_radius = 30;

	init_hole(&topleft, init_vector(tablex1, tabley1));
	init_hole(&topright, init_vector(tablex2, tabley1));
	init_hole(&midleft, init_vector(tablex1 - (borderlength * 0.3), (tabley2 + borderlength) * 0.5));
	init_hole(&midright, init_vector(tablex2 + (borderlength * 0.3), (tabley2 + borderlength) * 0.5));
	init_hole(&botleft, init_vector(tablex1, tabley2));
	init_hole(&botright, init_vector(tablex2, tabley2));
	//_________________________________________________________________________________________________________

	//Stick init_________________________________________________________________________________________________________
	Stick stick;
	init_stick(&stick, &cueball);

    InitWindow(screenWidth, screenHeight, "Pool");
    SetWindowPosition((MONITOR_WIDTH -screenWidth)/ 2, (MONITOR_HEIGHT - screenHeight)/ 2);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        update_stick(&stick, &cueball);
        //update_ball(&cueball, &stick);

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            //draw table______________________
            DrawRectangle(tablex1 - borderlength, tabley1 - borderlength, table_width + 2 * borderlength, tabley2 + 2 * borderlength, DARKBROWN); //Brown border
            DrawRectangle(tablex1, tabley1, table_width, tabley2 - tabley1, GREEN); //Green part
            //_____________________________________________

            //draw balls
            draw_ball(&cueball);
            draw_ball(&b);

            //draw holes__________________________
            draw_hole(&topleft);
            draw_hole(&topright);
            draw_hole(&midleft);
            draw_hole(&midright);
            draw_hole(&botleft);
            draw_hole(&botright);
            //____________________________________

            //draw stick____________________________
            draw_stick(&stick);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}