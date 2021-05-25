#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H

#include "../../../Image/Image.h"



#include "../../../Entity/Weapons/Weapon.h"


struct Point
{
  int x;
  int y;
};



struct Player
{

  explicit Player(Point pos = {.x = 10, .y = 10}) :
                 coords(pos), old_coords(coords) {

                 };

  bool Moved() const;
  void ProcessInput(MovementDir dir);
  void Draw( Image &player_sprite, double deltaTime);
  void nextAnim();


  Image *screen;


  bool is_moved = false;
  MovementDir shoot_dir = MovementDir::UP;
  int face = 0;
  int animation = 3;



  double animation_counter = 0.0f;
  int health_state = 0;
  bool change_animation = false;

  Weapon *weapon;

  void Define(Image &screen, Weapon &weapon);

  double health = 100.0;


  int getX() const {return coords.x;};
  int getY() const {return coords.y;};



  int map_coords_x;
  int map_coords_y;

  int global_player_x;
  int global_player_y;


  char **map;
  int room_size;
  int rooms_x;
  int rooms_y;


  int curr_room_x;
  int curr_room_y;


  bool isWin = false;
  bool isDead = false;



  Point coords {.x = 10, .y = 10};
  Point old_coords {.x = 10, .y = 10};
private:
  Pixel color {.r = 255, .g = 255, .b = 0, .a = 255};
  int move_speed = 1;

};

#endif //MAIN_PLAYER_H
