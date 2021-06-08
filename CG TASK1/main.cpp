#include "common.h"
#include "Image/Image.h"
#include "Entity/NPC/Player/Player.h"
#include "Entity/Weather/Fog.h"
#include "Entity/Weapons/Weapon.h"
#include "Entity/Effects/Animation.h"
#include "Entity/Textures/Symbols/Symbols.h"




#define GLFW_DLL
#include <GLFW/glfw3.h>


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

constexpr GLsizei WINDOW_WIDTH = 1024, WINDOW_HEIGHT = 768;//НЕ МЕНЯТЬ ИНАЧЕ ВСЕ СЛОМАЕТСЯ К ЧЕРТУ И ЕЩЕ КОМП СЛОМАЕТСЯ!!!!!!!!! ТОЛЬКО 1024х768!!!!!

struct InputState
{
  bool keys[1024]{}; //массив состояний кнопок - нажата/не нажата
  GLfloat lastX = 0, lastY = 0; //исходное положение мыши
  bool firstMouse = true;
  bool captureMouse         = true;  // Мышка захвачена нашим приложением или нет?
  bool capturedMouseJustNow = false;
} static Input;


GLdouble deltaTime = 0.0f;
GLdouble lastFrame = 0.0f;

double tip_counter = 0.0f;
bool tip_pressed = false;


int global_player_x;
int global_player_y;


void OnKeyboardPressed(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	switch (key)
	{
	case GLFW_KEY_ESCAPE:
		if (action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
		break;
  case GLFW_KEY_1:
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    break;
  case GLFW_KEY_2:
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    break;
	default:
		if (action == GLFW_PRESS)
      Input.keys[key] = true;
		else if (action == GLFW_RELEASE)
      Input.keys[key] = false;
	}
}

void processPlayerMovement(Player &player, double deltaTime, Image &screen, Animation &magic_effect_anim)
{
  if (Input.keys[GLFW_KEY_W])
    player.ProcessInput(MovementDir::UP);

  else if (Input.keys[GLFW_KEY_S])
    player.ProcessInput(MovementDir::DOWN);

  if (Input.keys[GLFW_KEY_A])
    player.ProcessInput(MovementDir::LEFT);

  else if (Input.keys[GLFW_KEY_D])
    player.ProcessInput(MovementDir::RIGHT);

/*
  if (Input.keys[GLFW_KEY_SPACE]){
    player.weapon->Fire(player.shoot_dir, deltaTime, player.getX(), player.getY());
    magic_effect_anim.DrawEffect(screen, player.getX() - 5,player.getY(), deltaTime);
  }
*/

//  if (Input.keys[GLFW_KEY_R])
//    player.weapon->Reload();

  // печатает все нажатые клавиши
  /*
  for (int i = 0; i < 1024; i++) {
    if(Input.keys[i])
    {
      std::cout << i << " " << Input.keys[i] << std::endl;
    }
  }
  */


}

void OnMouseButtonClicked(GLFWwindow* window, int button, int action, int mods)
{
  if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
    Input.captureMouse = !Input.captureMouse;

  if (Input.captureMouse)
  {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    Input.capturedMouseJustNow = true;
  }
  else
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

}

void OnMouseMove(GLFWwindow* window, double xpos, double ypos)
{
  if (Input.firstMouse)
  {
    Input.lastX = float(xpos);
    Input.lastY = float(ypos);
    Input.firstMouse = false;
  }

  GLfloat xoffset = float(xpos) - Input.lastX;
  GLfloat yoffset = Input.lastY - float(ypos);

  Input.lastX = float(xpos);
  Input.lastY = float(ypos);
}


void OnMouseScroll(GLFWwindow* window, double xoffset, double yoffset)
{
  // ...
}


int initGL()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize OpenGL context" << std::endl;
		return -1;
	}

	std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

  std::cout << "Controls: "<< std::endl;
  std::cout << "press right mouse button to capture/release mouse cursor  "<< std::endl;
  std::cout << "W, A, S, D - movement  "<< std::endl;
  std::cout << "M - minimap" << std::endl;
  std::cout << "press ESC to exit" << std::endl;

	return 0;
}

















int main(int argc, char** argv)
{
	if(!glfwInit())
    return -1;



//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);






  // Создаем окно
  GLFWwindow*  window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "task1 base project", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glfwSetKeyCallback        (window, OnKeyboardPressed);
	glfwSetCursorPosCallback  (window, OnMouseMove);
  glfwSetMouseButtonCallback(window, OnMouseButtonClicked);
	glfwSetScrollCallback     (window, OnMouseScroll);

	if(initGL() != 0)
		return -1;

  //Reset any OpenGL errors which could be present for some reason
	GLenum gl_error = glGetError();
	while (gl_error != GL_NO_ERROR)
		gl_error = glGetError();










  // Читаем карту
  int room_size = 12;// НЕ МЕНЯТЬ
  int rooms_x = 12;// Количество комнат по x (максимум 12!!!!!!)
  int rooms_y = 4;// Количество комнат по y

  const char *file = "./Maps/map.txt";


  char **map ;

  // создание
  map = new char * [room_size*rooms_x];
  for (int i = 0; i < room_size*rooms_x; i++)
      map[i] = new char [room_size*rooms_y];



  std::string line;


  int i = 0, j = 0;
  std::ifstream fstream( file ); // окрываем файл для чтения
  if (fstream.is_open())
  {
      while ( getline(fstream, line) )
      {
        for(i = 0; i < room_size*rooms_x; i++)
        {
          map[i][j] = line[i];
          //map[i][j] = line[i];
        }
        j++;
      }
  }
  fstream.close();     // закрываем файл




  // Записываем карту
  for(j = 0; j < room_size*rooms_y; j++){
    for(i = 0; i < room_size*rooms_x; i++){

      std::cout << map[i][j];
      if(map[i][room_size*rooms_y -  1 - j] == '@')
      {
        global_player_x = i;
        global_player_y = j;

      }

    }
    std::cout << std::endl;
  }















  //Создаем изображения бэкграунда
  Image block_img("./Entity/Textures/block.png");
  block_img.rotate180deg("./Entity/Textures/block.png");


  Image background("./Entity/Textures/background.jpg");
  background.rotate180deg("./Entity/Textures/background.jpg");


  Image victory_img("./Entity/Textures/victory.png");
  victory_img.rotate180deg("./Entity/Textures/victory.png");

  Image defeat_img("./Entity/Textures/defeat.png");
  defeat_img.rotate180deg("./Entity/Textures/defeat.png");


  Image screenBuffer(WINDOW_WIDTH, WINDOW_HEIGHT, 4);




  //Создаем оружия
  Image bullet_img("./Entity/Weapons/bullet.png");
  bullet_img.rotate180deg("./Entity/Weapons/bullet.png");
  Image pistol_1_img("./Entity/Weapons/pistol_1.png");
  pistol_1_img.rotate180deg("./Entity/Weapons/pistol_1.png");


  //Создаем туман
  Image fog("./Entity/Weather/fog.png");
  fog.rotate180deg("./Entity/Weather/fog.png");
  Fog fogObj;


  //Загружаем изображения для библиотеки symbols
  Symbols symbol;
  symbol.DefineSymbols();




  //Создаем игрока
  Image player_sprite("./Entity/NPC/Player/player.png");
  player_sprite.rotate180deg("./Entity/NPC/Player/player.png");

  Point starting_pos{.x = global_player_x%room_size * tileSize , .y = global_player_y%room_size * tileSize};
  Player player{starting_pos};
  player.global_player_x = global_player_x;
  player.global_player_y = global_player_y;


  player.map = map;
  player.room_size = room_size;
  player.rooms_x = rooms_x;
  player.rooms_y = rooms_y;





  Weapon pistol_1(screenBuffer, pistol_1_img, bullet_img, 17, 51, 1);
  player.Define(screenBuffer, pistol_1);







  //Анимация
  Image magic_effect_img("./Entity/Effects/magic_effect.png");
  magic_effect_img.rotate180deg("./Entity/Effects/magic_effect.png");
  Animation magic_effect_anim;
  magic_effect_anim.Define(magic_effect_img, 18, 5, 6, true);



  Image explosion_img("./Entity/Effects/explosion.png");
  explosion_img.rotate180deg("./Entity/Effects/explosion.png");
  Animation explosion_anim;
  explosion_anim.Define(explosion_img, 40, 9, 9, true);

  Image charge_img("./Entity/Effects/charge.png");
  charge_img.rotate180deg("./Entity/Effects/charge.png");
  Animation charge_anim;
  charge_anim.Define(charge_img, 5, 1, 5, true);


  Image torch_img("./Entity/Effects/torch.png");
  torch_img.rotate180deg("./Entity/Effects/torch.png");
  Animation torch_anim;
  torch_anim.Define(torch_img, 50, 1, 9, true);










  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);  GL_CHECK_ERRORS;
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); GL_CHECK_ERRORS;







  //Цикл игры
	while (!glfwWindowShouldClose(window))
	{

		GLdouble currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;



    glfwPollEvents();













    // Отрисовка  фона инвентаря
    for(int y = 0; y < screenBuffer.Height(); ++y)
      for(int x = screenBuffer.Height(); x < screenBuffer.Width(); ++x)
        screenBuffer.PutPixel(x, y, background.GetPixel(x,y) );



    //Перемещение в другую комнату
    int curr_room_x = player.global_player_x/12;
    int curr_room_y = player.global_player_y/12;

    if(player.getX() < 16 && curr_room_x != 0)
    {
      player.coords.x = WINDOW_HEIGHT - 129;
      player.global_player_x -=3;
    }
    if(player.getX() > WINDOW_HEIGHT - 64 - 17 && curr_room_x != rooms_x - 1)
    {
      //player.global_player_x = player.getX()/tileSize
      player.coords.x = 64;
      player.global_player_x +=3;
    }

    if(player.getY() > WINDOW_HEIGHT - 64 - 17 && curr_room_y != rooms_y - 1)
    {
      //player.global_player_x = player.getX()/tileSize
      player.coords.y = 64;
      player.global_player_y +=3;
    }
    if(player.getY() < 16 && curr_room_y != 0)
    {
      player.coords.y = WINDOW_HEIGHT - 129;
      player.global_player_y -=3;
    }

    player.curr_room_x = curr_room_x;
    player.curr_room_y = curr_room_y;
    //player.global_player_x%room_size



    // Отрисовка карты (на экране)
    for(int y = 0; y < screenBuffer.Height(); ++y)
      for(int x = 0; x < screenBuffer.Height(); ++x)
      {

        if(map[ x/tileSize + room_size*curr_room_x][ room_size*rooms_y - 1 - (y/tileSize +room_size*curr_room_y) ] == '#')
          screenBuffer.PutPixel(x, y, block_img.GetPixel(x%tileSize + 2*tileSize,y%tileSize) );

        else if(map[ x/tileSize  + room_size*curr_room_x][ room_size*rooms_y - 1 - (y/tileSize  + room_size*curr_room_y) ] == ' ')
          screenBuffer.PutPixel(x, y, block_img.GetPixel(x%tileSize + 1*tileSize,y%tileSize) );

        else if(map[ x/tileSize  + room_size*curr_room_x][ room_size*rooms_y - 1 - (y/tileSize  + room_size*curr_room_y) ] == 'C')
          screenBuffer.PutPixel(x, y, block_img.GetPixel(x%tileSize + 0*tileSize,y%tileSize) );

        else
        screenBuffer.PutPixel(x, y, block_img.GetPixel(x%tileSize + 0*tileSize,y%tileSize) );
      }




      //Печатаем подсказку
      int tip_x;
      int tip_y;

      for(int y = 0; y < screenBuffer.Height(); ++y){

        for(int x = 0; x < screenBuffer.Height(); ++x)
           if(map[ x/tileSize  + room_size*curr_room_x][ room_size*rooms_y - 1 - (y/tileSize  + room_size*curr_room_y) ] == 'C'){
              tip_x = x;
              tip_y = y;

           }
      }

    magic_effect_anim.DrawEffect(screenBuffer, tip_x-tileSize, tip_y-tileSize,  deltaTime);





    // Анализ действий игрока
    processPlayerMovement(player, deltaTime, screenBuffer, magic_effect_anim);




    //Разработка факела (старая)

    double contrast = 10;
    double contrast_R = 30;
    double contrast_G = 30;
    double contrast_B = 30;

    int xtor = 400,
    ytor = 400,
    rad = 256;


    for(int j = 0; j < rad; ++j)
        for(int i = 0; i < rad; ++i)
        {

          //право внмз до диагонали
          if( (rad - i) <= j )
          {
              if ( (rad - i) >= (rad - j) ){
                Pixel pix = screenBuffer.GetPixel(xtor+i,ytor+j);
                pix.r += double(j)*contrast_R/rad;
                pix.g += double(j)*contrast_G/rad;
                pix.b += double(j)*contrast_B/rad;
                if( (i-rad/2)*(i-rad/2) + (j-rad/2)*(j-rad/2) <= (64-rad/2)*(64-rad/2) )
                  screenBuffer.PutPixel(xtor+i, ytor+j, pix);

              }

              if ( (rad - i) < (rad - j) ){
                Pixel pix = screenBuffer.GetPixel(xtor+i,ytor+j);
                pix.r += double(i)*contrast_R/rad;
                pix.g += double(i)*contrast_G/rad;
                pix.b += double(i)*contrast_B/rad;
                //pix.b += 0 + (0 + i*2) ;
                if( (i-rad/2)*(i-rad/2) + (j-rad/2)*(j-rad/2) <= (64-rad/2)*(64-rad/2) )
                  screenBuffer.PutPixel(xtor+i, ytor+j, pix);

              }
              continue;
          }


            //лево ввех до диагонали
            if( (rad - i) >= j )
            {
                if (i>=j ){
                  Pixel pix = screenBuffer.GetPixel(xtor+i,ytor+j);
                  pix.r += double(contrast*j)*contrast_R/rad ;
                  pix.g += double(contrast*j)*contrast_G/rad ;
                  pix.b += double(contrast*j)*contrast_B/rad ;
                  if( (i-rad/2)*(i-rad/2) + (j-rad/2)*(j-rad/2) <= (64-rad/2)*(64-rad/2) )
                    screenBuffer.PutPixel(xtor+i, ytor+j, pix);

                }
                if (i<j ){
                  Pixel pix = screenBuffer.GetPixel(xtor+i,ytor+j);
                  pix.r += double(contrast*i)*contrast_R/rad ;
                  pix.g += double(contrast*i)*contrast_G/rad ;
                  pix.b += double(contrast*i)*contrast_B/rad ;
                  if( (i-rad/2)*(i-rad/2) + (j-rad/2)*(j-rad/2) <= (64-rad/2)*(64-rad/2) )
                    screenBuffer.PutPixel(xtor+i, ytor+j, pix);


                }
                continue;

            }


        }
    //torch_anim.DrawEffect(screenBuffer, xtor, ytor,  deltaTime);



    player.Draw( player_sprite, deltaTime);

    //Печатать патроны игрока
    /*
    std::string string_coord = std::to_string(player.weapon->ammoClip) + "/" + std::to_string(player.weapon->ammoAll);
    symbol.DrawWord(screenBuffer, deltaTime, player.getX(), player.getY()+55, string_coord );
    */


    if(map[ (player.getX() + tileSize/2 )/tileSize + room_size*curr_room_x][ room_size*rooms_y - 1 -  ( (player.getY() + tileSize/2 )/tileSize +room_size*curr_room_y) ] == 'Q')
    {
      player.isWin = true;

    }
    if(map[ (player.getX() + tileSize/2 )/tileSize + room_size*curr_room_x][ room_size*rooms_y - 1 -  ( (player.getY() + tileSize/2 )/tileSize +room_size*curr_room_y) ] == 'C')
    {
      tip_pressed = true;

    }











    //Печатать координаты игрока
    std::string string_coord = std::to_string(player.getX()) + " " + std::to_string(player.getY());
    symbol.DrawWord(screenBuffer, deltaTime, player.getX()-10, player.getY()+55, string_coord );

    player.map_coords_x = player.getX()/tileSize;
    player.map_coords_y = player.getY()/tileSize;

    //Печатать координаты игрока на карте
    string_coord =  "Map coord: " + std::to_string( player.map_coords_x   ) + " " + std::to_string( player.map_coords_y );
    symbol.DrawWord(screenBuffer, deltaTime, 780, 500, string_coord );

    //Печатать координаты игрока (через глобальные)
    string_coord =  "player coord: " + std::to_string(  player.global_player_x%room_size * tileSize )  + " " + std::to_string(player.global_player_y%room_size * tileSize ) ;
    symbol.DrawWord(screenBuffer, deltaTime, 780, 450, string_coord );


    //Печатать глобальные координаты
    string_coord = "Global coord: " + std::to_string(player.global_player_x) + " " + std::to_string(player.global_player_y);
    symbol.DrawWord(screenBuffer, deltaTime, 780, 400, string_coord );

    //Печатать координаты в комнате


    //Печатать здоровье игрока
    string_coord = std::to_string( int(player.health) );
    if( int(player.health) < 10 )
    {
      string_coord = std::to_string(0) + std::to_string( int(player.health) );
    }
    symbol.DrawWord(screenBuffer, deltaTime, 885, 690, string_coord );



    if(tip_pressed)
      symbol.DrawGlobalMessage(screenBuffer, deltaTime, 10, 7, "tip: Wash your hands boyz!!!", tip_counter , tip_pressed );


    // здесь рисуем анимацию зарядки
    charge_anim.DrawEffect(screenBuffer, 775,550, deltaTime);




    // Здесь будет код для отрисовки тумана
    fogObj.Draw(screenBuffer, fog, deltaTime);



    // Отрисовка карты (глобальная через клавишу)
    int pix_size = 7;// НЕ БОЛЬШЕ 7!!!!!!
    if (Input.keys[GLFW_KEY_M])
      for(int y = 0; y < room_size*pix_size*rooms_y; ++y)
        for(int x = 0; x < room_size*pix_size*rooms_x; ++x)
        {
          if(map[x/pix_size][y/pix_size] == '#')
            screenBuffer.PutPixel(x, WINDOW_HEIGHT - 1 - y,   block_img.GetPixel((x*pix_size*rooms_x)%tileSize + 2*tileSize, (y*pix_size*rooms_y)%tileSize) );

          else if(map[x/pix_size][y/pix_size] == ' ')
            screenBuffer.PutPixel(x, WINDOW_HEIGHT - 1 - y,   block_img.GetPixel((x*pix_size*rooms_x)%tileSize + 1*tileSize, (y*pix_size*rooms_y)%tileSize) );

          else
          screenBuffer.PutPixel(x, WINDOW_HEIGHT - 1 - y,   block_img.GetPixel((x*pix_size*rooms_x)%tileSize + 0*tileSize, (y*pix_size*rooms_y)%tileSize) );
        }













    if(player.isWin){


          for(int y = 0; y < screenBuffer.Height(); ++y)
            for(int x = 0; x < screenBuffer.Width(); ++x)
              if( victory_img.GetPixel(x,y).a)
                screenBuffer.PutPixel(x, y, victory_img.GetPixel(x,y) );




          // Отрисовка проведенных расчетов
          glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); GL_CHECK_ERRORS;
          glDrawPixels (WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, screenBuffer.Data()); GL_CHECK_ERRORS;

          glfwSwapBuffers(window);



          GLdouble defeat_time1 = glfwGetTime();
          GLdouble timer = 0.0f;

          while(timer < 5.0f  )
          {
            GLdouble defeat_time2 = glfwGetTime();
            timer += defeat_time2 - defeat_time1;
            defeat_time1 = defeat_time2;
          }

          break;
        }

    // Отрисовка поражения
    if(player.isDead){



      for(int y = 0; y < screenBuffer.Height(); ++y)
        for(int x = 0; x < screenBuffer.Width(); ++x)
          if( defeat_img.GetPixel(x,y).a)
            screenBuffer.PutPixel(x, y, defeat_img.GetPixel(x,y) );




      // Отрисовка проведенных расчетов
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); GL_CHECK_ERRORS;
      glDrawPixels (WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, screenBuffer.Data()); GL_CHECK_ERRORS;

      glfwSwapBuffers(window);



      GLdouble defeat_time1 = glfwGetTime();
      GLdouble timer = 0.0f;

      while(timer < 5.0f  )
      {
        GLdouble defeat_time2 = glfwGetTime();
        timer += defeat_time2 - defeat_time1;
        defeat_time1 = defeat_time2;
      }

      break;
    }


    // Отрисовка проведенных расчетов
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); GL_CHECK_ERRORS;
    glDrawPixels (WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, screenBuffer.Data()); GL_CHECK_ERRORS;

		glfwSwapBuffers(window);


	}



  // уничтожение массива map
  for (int i = 0; i < room_size*rooms_x; i++) {
      delete [] map[i];
  }
  delete [] map;

	glfwTerminate();
	return 0;
}
