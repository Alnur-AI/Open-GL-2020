#ifndef MAIN_IMAGE_H
#define MAIN_IMAGE_H

#include <string>

#include <iostream>

constexpr int tileSize = 64;


struct Pixel
{
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;

};

enum class MovementDir
{
  UP,
  DOWN,
  LEFT,
  RIGHT
};



constexpr Pixel backgroundColor{0, 0, 255, 255};


struct Image
{
  explicit Image(const std::string &a_path);
  Image(int a_width, int a_height, int a_channels);

  int Save(const std::string &a_path);
  int rotate180deg (const std::string &a_path);

  int Width()    const { return width; }
  int Height()   const { return height; }
  int Channels() const { return channels; }
  size_t Size()  const { return size; }
  Pixel* Data()        { return  data; }

  void print(Image &screen);


  Image* Adress() {return this;}
  bool rotated = false;

  uint8_t getR() const {return data->r;} ;
  uint8_t getG() const {return data->g;} ;
  uint8_t getB() const {return data->b;} ;
  uint8_t getA() const {return data->a;} ;


  void setR(uint8_t r) const { data->r = r;} ;
  void setG(uint8_t g) const { data->g = g;} ;
  void setB(uint8_t b) const { data->b = b;} ;
  void setA(uint8_t a) const { data->a = a;} ;

  std::string str;

  Pixel GetPixel(int x, int y){
    if( x >= Width() )
      std::cout << "GetPixel: wrong x" << " " << str << std::endl;
    if( y >= Height() && (rotated) )
      std::cout << "GetPixel: wrong y" << " " << str << std::endl;

    return data[width * y + x];
  }
  void  PutPixel(int x, int y, const Pixel &pix) {
    if( x >= Width() )
      std::cout << "PutPixel: wrong x" << " " << this << std::endl;
    if( y >= Height() )
      std::cout << "PutPixel: wrong y" << " " << this << std::endl;

    data[width* y + x] = pix;
  }
  void AlphaPixel(int x, int y, const Pixel &pix) {


    int alpha1 = data[width*y + x].a;
    int alpha2 = pix.a;

    int Fa = 1;
    int Fb = 1;

    data[width*y + x].r = (data[width*y + x].r*Fa  + pix.r*Fb )/(Fa+Fb) ;
    data[width*y + x].g = (data[width*y + x].g*Fa  + pix.g*Fb )/(Fa+Fb) ;
    data[width*y + x].b = (data[width*y + x].b*Fa  + pix.b*Fb )/(Fa+Fb) ;
    data[width*y + x].a = Fa+Fb  ;

    /*
    //working version
    int alpha1 = data[width*y + x].a;
    int alpha2 = pix.a;

    int Fa = 1;
    int Fb = 1;

    data[width*y + x].r = (data[width*y + x].r*Fa  + pix.r*Fb )/(Fa+Fb) ;
    data[width*y + x].g = (data[width*y + x].g*Fa  + pix.g*Fb )/(Fa+Fb) ;
    data[width*y + x].b = (data[width*y + x].b*Fa  + pix.b*Fb )/(Fa+Fb) ;
    data[width*y + x].a = Fa+Fb  ;
    */




  }
  ~Image();

private:
  int width = -1;
  int height = -1;
  int channels = 3;
  size_t size = 0;
  Pixel *data = nullptr;
  bool self_allocated = false;
};



#endif //MAIN_IMAGE_H
