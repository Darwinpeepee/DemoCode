#include "graphics.h"
#include <iostream>



// The custom callback function that the library calls 
// to check for and set the current application state.
void update(float ms)
{   
    
    graphics::MouseState mouse;
    graphics::getMouseState(mouse);

   
    bool enter_pressed = graphics::getKeyState(graphics::scancode_t::SCANCODE_F1);
    if (enter_pressed || mouse.button_left_released)
    {
        std::cout << enter_pressed;
        graphics::stopMusic();
        graphics::playSound("assets\\Squid Game Sound Effect.wav", 1.0f, false);
    }
   
}

// The window content drawing function.
void draw()
{
    graphics::Brush br;

    /*graphics::setOrientation(0);*/

    br.texture = "assets\\squid_game.png";
    br.outline_opacity = 0.0f;

    graphics::drawRect(500, 93, 200, 200, br);

    br.fill_color[0] = 0.2f;
    br.fill_color[1] = 0.0f;
    br.fill_color[2] = 0.1f;

    graphics::resetPose();
    drawText(130, 450, 50, "Press   enter   to   start", br);

    graphics::resetPose();
     br.fill_color[0] = 0.2f;
    br.fill_color[1] = 0.0f;
    br.fill_color[2] = 0.1f;
    br.texture = "assets\\image.png";
    br.outline_opacity = 0.0f;

    graphics::drawRect(500, 280, 200, 200, br);

}

int main()
{
    graphics::createWindow(1200, 600, "Squid Game");

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(1000, 500);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    graphics::playMusic("assets\\let-the-game-begin.wav", 1.0f, true);

   /* graphics::Brush br;
    br.fill_color[0] = 0.5f;
    br.fill_color[1] = 0.7f;
    br.fill_color[2] = 0.9f;
    graphics::setWindowBackground(br);*/

    graphics::setFont("assets\\GameOfSquids.ttf");

    graphics::startMessageLoop();

    return 0;
}