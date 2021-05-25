#include "Animation.h"

//Удали потом
#include <iostream>

void Animation::Define(Image &img,int multy , int xAnim, int yAnim, bool isInfinite)
{
  xAnimations = xAnim;
  yAnimations = yAnim;

  anim_speed = multy;

  anim = &img;

  this->isInfinite = isInfinite;
}


void Animation::DrawEffect(Image &screen, int coords_x, int coords_y, double deltaTime)
{
  Pixel pix;
  animation_counter += (deltaTime*anim_speed);


  int animSize;
  if (anim->Width() / xAnimations > anim->Height() /yAnimations)
    animSize = anim->Height() /yAnimations;
  else
    animSize = anim->Width() / xAnimations;



  if (animation_counter > 5 && stopAnimation == false)
  {
    if(isInfinite == false && anim_state_x == xAnimations - 1 && anim_state_y == yAnimations - 1){
      stopAnimation = true;

    }
    anim_state_x++;

    if (anim_state_x >= xAnimations)
    {
      anim_state_y++;
      anim_state_x = 0;

      if (anim_state_y >= yAnimations)
      {
        anim_state_x = 0;
        anim_state_y = 0;
      }
    }

    animation_counter = 0;
  }



    // Код для отрисовки анимации
    //anim->Width() / xAnimations
    //anim->Height() /yAnimations
    /*
    for(int y = coords_y; y < animSize + coords_y; ++y)
    {
      if (  y >= screen.Height() ) continue;

      for(int x = coords_x; x < animSize + coords_x; ++x)
      {
        if (  x >= screen.Width() ) continue;

        pix = anim->GetPixel( x - coords_x + anim_state_x*animSize,   anim->Height()-(y-coords_y ) - 1  - anim_state_y*animSize  );
        if(int(pix.a))
          screen.PutPixel(x, y, pix );

      }
    }
    */
    for(int y = coords_y; y < animSize + coords_y-1; ++y)
    {
      if (  y >= screen.Height() ) continue;

      for(int x = coords_x; x < anim->Width() / xAnimations + coords_x; ++x)
      {
        if (  x >= screen.Width() ) continue;

        pix = anim->GetPixel( x - coords_x + anim_state_x*(anim->Width() / xAnimations),   anim->Height()-(y-coords_y ) - 1  - anim_state_y*(anim->Height() /yAnimations)  );
        if(int(pix.a))
          screen.PutPixel(x, y, pix );

      }
    }






}
