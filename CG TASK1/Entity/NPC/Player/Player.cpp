#include "Player.h"

//удали потом
#include <iostream>


Image health_img ("./Entity/NPC/Player/health.png");


bool Player::Moved() const
{

  if(coords.x == old_coords.x && coords.y == old_coords.y)
    return false;
  else
    return true;
}

void Player::Define(Image &screen, Weapon &weapon)
{
  health_img.rotate180deg ("./Entity/NPC/Player/health.png");

  this->screen = &screen;
  this->weapon = &weapon;
}

void Player::ProcessInput(MovementDir dir)
{
  int move_dist = move_speed;
  shoot_dir = dir;
  switch(dir)
  {

    case MovementDir::UP:

      //Коллизия с блоками
      if(map[ (getX() )/tileSize + room_size*curr_room_x][ room_size*rooms_y - 1 -  ( (getY() + tileSize +1)/tileSize +room_size*curr_room_y) ] == '#'
      ||map[ (getX() + tileSize )/tileSize + room_size*curr_room_x][ room_size*rooms_y - 1 -  ( (getY() + tileSize +1 )/tileSize +room_size*curr_room_y) ] == '#'
      && coords.x % tileSize != 0
      )
        break;


      old_coords.y = coords.y;
      coords.y += move_dist;



      if(Moved() && getY()%tileSize == 0 && getY() != 703 )
        global_player_y++;
      face = 0;








      if (coords.y >= screen->Height() - tileSize ){ coords.y = old_coords.y ;  }




      break;

    case MovementDir::DOWN:



      //Коллизия с блоками
      if(map[ (getX() )/tileSize + room_size*curr_room_x][ room_size*rooms_y - 1 -  ((getY() -1 )/tileSize +room_size*curr_room_y) ] == '#'
      ||map[ (getX() )/tileSize + room_size*curr_room_x + 1][ room_size*rooms_y - 1 -  ((getY() -1)/tileSize +room_size*curr_room_y) ] == '#'
      //&& coords.x % tileSize != 0
      )
        break;



      old_coords.y = coords.y;
      coords.y -= move_dist;



      if(Moved() && getY()%tileSize == 0 && getY() != 0){
        global_player_y--;
      }
      face = 3;







      if(coords.y < 0){ coords.y = old_coords.y; }


      break;

    case MovementDir::LEFT:




      //Коллизия с блоками
      if(map[ (getX() - 1 )/tileSize + room_size*curr_room_x][ room_size*rooms_y - 1 -  ( (getY() )/tileSize +room_size*curr_room_y) ] == '#'
      || map[ (getX() -1)/tileSize + room_size*curr_room_x][ room_size*rooms_y - 1 -  ( (getY() + tileSize)/tileSize +room_size*curr_room_y) ] == '#'
      && coords.y % tileSize != 0
      )
        break;

      old_coords.x = coords.x;
      coords.x -= move_dist;



      if(Moved() && getX()%tileSize == 0 && getX() != 0 ){
        global_player_x--;

      }

      if(coords.x < 0 ){coords.x =  old_coords.x; }

      face = 2;
      break;

    case MovementDir::RIGHT:





      //Коллизия с блоками
      if(map[ (getX() + tileSize+1)/tileSize + room_size*curr_room_x][ room_size*rooms_y - 1 -  ( (getY()  +tileSize)/tileSize +room_size*curr_room_y) ] == '#'
      ||map[ (getX() + tileSize+1)/tileSize + room_size*curr_room_x][ room_size*rooms_y - 1 -  ( (getY() )/tileSize +room_size*curr_room_y) ] == '#'

      )
        break;



      old_coords.x = coords.x;
      coords.x += move_dist;



      if(Moved() && getX()%tileSize == 0 && getX() != 703 ){
        global_player_x++;
      }


      if(coords.x >= screen->Height() - tileSize){ coords.x = old_coords.x; }

      face = 1;
      break;






    default:
      break;


  }


}




void Player::Draw(Image &player_sprite, double deltaTime)
{

  Pixel pix;
  int xmax = screen->Width();
  int ymax = screen->Height() ;

  animation_counter += deltaTime;
  if(animation_counter > 0.3){
    animation_counter = 0;
    change_animation = true;
  }



  if ( 90 <= health && health <= 100 )
    health_state = 6;

  if ( 75 <= health && health < 90)
    health_state = 5;

  if (50 <= health && health < 75)
    health_state = 4;

  if (25 <= health && health < 50)
    health_state = 3;

  if (10 <= health && health < 25)
    health_state = 2;

  if (0 < health  && health < 10)
    health_state = 1;

  if ( health == 0 )
    health_state = 0;




  if(health <= 0.0)
    isDead = true;



    if(map[ (getX() + tileSize/2 )/tileSize + room_size*curr_room_x][ room_size*rooms_y - 1 -  ( (getY() + tileSize/2 )/tileSize +room_size*curr_room_y) ] == ' ')
      health -= (10*deltaTime);



  if( Moved() )
  {
    for(int y = old_coords.y, v = face * (tileSize - 1)+1; y <= old_coords.y + tileSize; ++y, ++v)
    {
      for(int x = old_coords.x,  u = animation * (tileSize - 1)+1; x <= old_coords.x + tileSize; ++x, ++u)
      {
        pix = player_sprite.GetPixel(u, v);

        if(int(pix.a))
          screen->PutPixel(x, y, pix);


        //std::cout << coords.x << " " << coords.y << std::endl;
        //std::cout << &health_img << std::endl;


      }
    }

    if(change_animation){
      nextAnim();
      change_animation = false;
    }


    old_coords = coords;
  }
  else
  {
      animation = 0;
  }


  // Дочищаем прошлый кадр

  for(int y = coords.y, v = face * (tileSize - 1)+1; y <= coords.y + tileSize; ++y, ++v)
  {
    for(int x = coords.x,  u = animation * (tileSize - 1)+1; x <= coords.x + tileSize; ++x, ++u)
    {
      pix = player_sprite.GetPixel(u, v);
      if(int(pix.a))
      {
        screen->PutPixel(x, y, pix);
      }

    }
  }



  // рисуем сердце


  for(int y = ymax - health_img.Height() - 10, v = 1; y < ymax - 10; ++y, ++v)
  {
    if (v >= health_img.Height())
      break;

    for(int x = xmax - health_img.Height() - 65 ,  u = health_state * (health_img.Height() - 1  ) + 1; x < xmax - 65; ++x, ++u)
    {
      if (u >=  health_img.Width() )
        break;

      pix = health_img.GetPixel(u, v);
      if(int(pix.a))
        screen->PutPixel(x-health_state, y, pix);

    }
  }






}

void Player::nextAnim()
{
  animation ++ ;

  if(animation > 3){
    animation = 0;
  }

}
