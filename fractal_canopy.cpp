#include <stdio.h>
#include "raylib.h"
#include "raymath.h" // for DEG2RAD
#include <math.h>

#define SCREEN_WIDTH 800  // x-axis
#define SCREEN_HEIGHT 650  // y-axis
#define BRANCH_COLOR GREEN
#define BRANCH_OFF_ANGLE 20 * DEG2RAD


void DrawCanopy(float x, float y, float length, float angle, float thickness) {
	
	// Base case (When length reaches 0)
	if(length <= 1) {
		return;
	}
	
	
	float X_Rotate = x + cosf(angle) * length;
	float Y_Rotate = y + sinf(angle) * length;

	Vector2 start = { x, y };
	Vector2 end = { X_Rotate, Y_Rotate };
	DrawLineEx(start, end, thickness, BRANCH_COLOR);
	// DrawLineEx(start, rotLine, thickness, BRANCH_COLOR);
	// DrawCircleV(Vector2 center, float radius, Color color);
	// DrawCircleV(start, 5.0f, RAYWHITE);
	// DrawCircleV(end, 5.0f, BLUE);
	// DrawCircleV(rotLine, 3.0f, MAGENTA);
	
	DrawCanopy(X_Rotate, Y_Rotate, length * 0.7, angle - BRANCH_OFF_ANGLE, thickness * 0.7f);
        DrawCanopy(X_Rotate, Y_Rotate, length * 0.7, angle + BRANCH_OFF_ANGLE, thickness * 0.7f);
}


int main(void) {

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "fractal canopy - window");
	SetTargetFPS(1);

	while(!WindowShouldClose()) {

		BeginDrawing();
			ClearBackground(BLACK);
			// void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color);
			DrawCanopy(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT - 20.0f, 200.0f, -90.0f * DEG2RAD, 15.0f );
			// DrawText("Congrats ! I have created my first window !", 190, 200, 20, GREEN);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
