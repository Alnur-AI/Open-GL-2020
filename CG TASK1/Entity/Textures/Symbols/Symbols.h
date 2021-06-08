#ifndef SYMBOLS_H
#define SYMBOLS_H

#include "../../../Image/Image.h"

#include <iostream>
#include <string>




struct Symbols
{
  double animation_counter = 0.0f;

  void DefineSymbols();

  void DrawLetter(Image &screen, Image &symbol, double deltaTime, int coord_x, int coord_y);

  void DrawWord(Image &screen, double deltaTime, int coord_x, int coord_y, std::string message);

  void DrawGlobalMessage(Image &screen, double deltaTime, int coord_x, int coord_y, std::string message, double &counter, bool &isActive);

  Image* CharToImage(char letter);

};




#endif //SYMBOLS_H
