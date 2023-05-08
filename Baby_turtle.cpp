#include "Baby_turtle.hpp"

float BABY_TURTLE_SPEED = 1;

const int FRAMENUM = 17;
const float FRAMESIZE = 0.3;

const float TIME_ANIMATION = 1.0;
const float DELAY_ANIMATION = 3.0;
float DELAY_TIME = 0.0;

Baby_turtle::Baby_turtle(string file_name, vector<Texture> *frames_)
    : Person(file_name, BABY_TURTLE_SPEED)
{
    this->frames = frames_;

    int ran = rand() % 2;
    switch (ran)
    {
    case 1:
    {
        this->cur_dir = {1.f, 0.f};
        break;
    }
    case 0:
        this->cur_dir = {-1.f, 0.f};
        break;
    }
    // set the first frame
    cur_frame = 0;
    sprite.setScale(FRAMESIZE, FRAMESIZE);
}

void Baby_turtle::default_movement(bool is_move_valid, bool is_in_map)
{
    if (!is_move_valid || !is_in_map)
    {
        this->cur_dir = {-cur_dir.x, -cur_dir.y};
        this->move(cur_dir.x, cur_dir.y);
    }
}

void Baby_turtle::update_frame()
{
    if (cur_frame < (FRAMENUM - 1))
    {
        cur_frame += 1;
    }
    else
    {
        cur_frame = 1;
    }
}

void Baby_turtle::move_left_animation()
{
    sprite.setScale(FRAMESIZE, FRAMESIZE);
    if (is_on_earth_() && delay())
    {
        update_frame();
        sprite.setTexture((*frames)[cur_frame]);
        sprite.setScale(FRAMESIZE, FRAMESIZE);
    }
}

void Baby_turtle::move_right_animation()
{
    sprite.setScale(-FRAMESIZE, FRAMESIZE);
    if (is_on_earth_() && delay())
    {
        update_frame();
        sprite.setTexture((*frames)[cur_frame]);
        sprite.setScale(-FRAMESIZE, FRAMESIZE);
    }
}

bool Baby_turtle::delay()
{
    DELAY_TIME += TIME_ANIMATION;
    if (DELAY_TIME - DELAY_ANIMATION >= 0.0)
    {
        DELAY_TIME = 0.0;
        return true;
    }
    return false;
}
