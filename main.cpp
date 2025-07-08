#include"raylib.h"

int main(void)
{
   const int width = 800;
   const int height = 480;
   InitWindow(width, height, "raylib [core] example - model loading");
   
   Camera camera = { 0 };
   camera.position = (Vector3){10.f, 10.f, 10.f};
   camera.target = (Vector3){0.0f, 0.0f, 0.0f};
   camera.up = (Vector3){0.0f, 1.0f, 0.0f};
   camera.fovy = 39.0f;
   camera.projection = CAMERA_PERSPECTIVE;

   Model model = LoadModel("sally_carrera/scene.gltf");
   Vector3 position = {0.0f, 0.0f, 0.0f};

   BoundingBox bounds = GetMeshBoundingBox(model.meshes[0]);

   bool selected = false;

   DisableCursor();

   SetTargetFPS(120);

   while (!WindowShouldClose())
   {
       UpdateCamera(&camera, CAMERA_FREE);

       if(IsFileDropped())
       {
           FilePathList droppedFiles = LoadDroppedFiles();
           if(droppedFiles.count == 1) //Only support one file dropped
           {
               if(IsFileExtension(droppedFiles.paths[0], ".obj") ||
                  IsFileExtension(droppedFiles.paths[1], ".gltf")||
                  IsFileExtension(droppedFiles.paths[2], ".glb") ||
                  IsFileExtension(droppedFiles.paths[3], ".vox") ||
                  IsFileExtension(droppedFiles.paths[4], ".iqm") ||
                  IsFileExtension(droppedFiles.paths[5], ".m3d"))
               {
                   UnloadModel(model);
                   model = LoadModel(droppedFiles.paths[0]);
                   bounds = GetMeshBoundingBox(model.meshes[0]);
               }
           }

           UnloadDroppedFiles(droppedFiles);
       }

       if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
       {
           if(GetRayCollisionBox(GetScreenToWorldRay(GetMousePosition(), camera), bounds).hit) selected = !selected;
           else selected = false;
       }



       BeginDrawing();

       ClearBackground(RAYWHITE);

       BeginMode3D(camera);
       DrawModel(model, position, 1.0f, WHITE);
       DrawGrid(20, 10.0f);
       if(selected) DrawBoundingBox(bounds, GREEN);
       EndMode3D();

       DrawText("Drag & drop model to load mesh/texture.", 10, GetScreenHeight() - 20, 10, DARKGRAY);
       if(selected) DrawText("MODEL SELECTED", GetScreenWidth() - 110, 10, 10, GREEN);

       DrawText("(c) Ferrari model", width - 200, height - 20, 10, GRAY);

       DrawFPS(10, 10);

       EndDrawing();
   }

   UnloadModel(model);

   CloseWindow();

   return 0;
}

