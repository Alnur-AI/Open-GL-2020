#include "Fog.h"

//Удали потом
#include <iostream>


void Fog::Draw(Image &screen, Image &fog, double deltaTime)
{
  uint32_t animation = 0;
  int new_x[ fog.Width() ];


  animation_counter += (deltaTime+0.5);

  animation = int(animation_counter);






  for(int y = tileSize; y < fog.Height()-tileSize; ++y)
  {

    //Кольцо высчетов по модулю х чтобы туман смещался
    for (int i = 0; i < fog.Width(); i++){
      new_x[i] = (i + animation)%fog.Height();
      //std::cout << new_x[i] << std::endl;
    }



    for(int x = tileSize ; x < fog.Height()-tileSize ; ++x)
    {
      if( int( fog.GetPixel(new_x[x], y).a ) )
        screen.AlphaPixel(x, y, fog.GetPixel(new_x[x],y) );
    }



  }

  //std::cout << change_animation << " " << animation << std::endl;





}
