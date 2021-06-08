#ifndef ANIMATION_H
#define ANIMATION_H

#include "../../Image/Image.h"





struct Animation
{
  double animation_counter = 0.0f;
  bool change_animation = false;

  int anim_speed = 1;

  int anim_state_x = 0;
  int anim_state_y = 0;

  int xAnimations = 0;
  int yAnimations = 0;

  bool isInfinite = true;
  bool stopAnimation = false;
  Image *anim;

  void Define(Image &img,int multy, int xAnim, int yAnim, bool isInfinite);
  void DrawEffect(Image &screen, int coords_x, int coords_y, double deltaTime);




};


#endif //ANIMATION_H
