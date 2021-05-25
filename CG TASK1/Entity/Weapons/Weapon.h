#ifndef WEAPON_H
#define WEAPON_H

#include "../../Image/Image.h"




struct Weapon
{
  Image *screen;
  Image *weapon_img;
  Image *bullet_img;

  int ammoClip = 17;
  int ammoAll = 51;

  int fireSpeed = 3;
  int FullClip = 17;
  int FullAmmo = 51;


  int xmax = 1024;
  int ymax = 768;


  double shoot_counter = 0;



  Weapon (Image &screen, Image &weapon_img, Image &bullet_img, int FullClip, int FullAmmo, int fireSpeed)
  {
    this->screen = &screen;
    this->weapon_img = &weapon_img;
    this->bullet_img = &bullet_img;

    this->fireSpeed = fireSpeed;
    this->FullClip = FullClip;
    this->FullAmmo = FullAmmo;

    this->xmax = screen.Width();
    this->ymax = screen.Height();

  };

  void Define(Image &screen, Image &weapon_img, Image &bullet_img,  int FullClip, int FullAmmo, int fireSpeed)
  {
    this->screen = &screen;
    this->weapon_img = &weapon_img;
    this->bullet_img = &bullet_img;

    this->fireSpeed = fireSpeed;
    this->FullClip = FullClip;
    this->FullAmmo = FullAmmo;

    this->xmax = screen.Width();
    this->ymax = screen.Height();

  };


  void Fire(MovementDir dir, double deltaTime, int coords_x, int coords_y)
  {
    shoot_counter += deltaTime;
    if(shoot_counter > 0.75)
    {

      if(ammoClip <= 0 && ammoAll <= 0)
        return;

      ammoClip--;

      if(ammoClip <= 0)
        Reload();

      shoot_counter = 0;
    }
  };
  void Reload()
  {
    if ( ammoAll == 0 || ammoClip == FullAmmo )
      return;

    ammoClip = FullClip;
    ammoAll -= ammoClip;


  };


  void Draw(Image &screen, Image &fog, double deltaTime);


};


#endif //WEAPON_H
