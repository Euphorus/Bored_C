#include<stdio.h>
#include <raylib.h>

int main(void)
{
	InitWindow(600, 600, "Raylib - basic window");

	while (!WindowShouldClose())
	{
		BeginDrawing();

			ClearBackground(RAYWHITE);

			DrawText("Congrats! You created your first window!", 90, 200, 20, RED);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}