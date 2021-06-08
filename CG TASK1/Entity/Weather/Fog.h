#ifndef FOG_H
#define FOG_H

#include "../../Image/Image.h"



struct Fog
{
  double animation_counter = 0.0f;
  bool change_animation = false;

  void Draw(Image &screen, Image &fog, double deltaTime);


};


#endif //FOG_H
