#include "Symbols.h"

Image A_img("./Entity/Textures/Symbols/BigLetEng/A.png");
Image B_img("./Entity/Textures/Symbols/BigLetEng/B.png");
Image C_img("./Entity/Textures/Symbols/BigLetEng/C.png");
Image D_img("./Entity/Textures/Symbols/BigLetEng/D.png");
Image E_img("./Entity/Textures/Symbols/BigLetEng/E.png");
Image F_img("./Entity/Textures/Symbols/BigLetEng/F.png");
Image G_img("./Entity/Textures/Symbols/BigLetEng/G.png");
Image H_img("./Entity/Textures/Symbols/BigLetEng/H.png");
Image I_img("./Entity/Textures/Symbols/BigLetEng/I.png");
Image J_img("./Entity/Textures/Symbols/BigLetEng/J.png");
Image K_img("./Entity/Textures/Symbols/BigLetEng/K.png");
Image L_img("./Entity/Textures/Symbols/BigLetEng/L.png");
Image M_img("./Entity/Textures/Symbols/BigLetEng/M.png");
Image N_img("./Entity/Textures/Symbols/BigLetEng/N.png");
Image O_img("./Entity/Textures/Symbols/BigLetEng/O.png");
Image P_img("./Entity/Textures/Symbols/BigLetEng/P.png");
Image Q_img("./Entity/Textures/Symbols/BigLetEng/Q.png");
Image R_img("./Entity/Textures/Symbols/BigLetEng/R.png");
Image S_img("./Entity/Textures/Symbols/BigLetEng/S.png");
Image T_img("./Entity/Textures/Symbols/BigLetEng/T.png");
Image U_img("./Entity/Textures/Symbols/BigLetEng/U.png");
Image V_img("./Entity/Textures/Symbols/BigLetEng/V.png");
Image W_img("./Entity/Textures/Symbols/BigLetEng/W.png");
Image X_img("./Entity/Textures/Symbols/BigLetEng/X.png");
Image Y_img("./Entity/Textures/Symbols/BigLetEng/Y.png");
Image Z_img("./Entity/Textures/Symbols/BigLetEng/Z.png");


/*
Image a_img("./Entity/Textures/Symbols/SmaLetEng/a.png");
Image b_img("./Entity/Textures/Symbols/SmaLetEng/b.png");
Image c_img("./Entity/Textures/Symbols/SmaLetEng/c.png");
Image d_img("./Entity/Textures/Symbols/SmaLetEng/d.png");
Image e_img("./Entity/Textures/Symbols/SmaLetEng/e.png");
Image f_img("./Entity/Textures/Symbols/SmaLetEng/f.png");
Image g_img("./Entity/Textures/Symbols/SmaLetEng/g.png");
Image h_img("./Entity/Textures/Symbols/SmaLetEng/h.png");
Image i_img("./Entity/Textures/Symbols/SmaLetEng/i.png");
Image j_img("./Entity/Textures/Symbols/SmaLetEng/j.png");
Image k_img("./Entity/Textures/Symbols/SmaLetEng/k.png");
Image l_img("./Entity/Textures/Symbols/SmaLetEng/l.png");
Image m_img("./Entity/Textures/Symbols/SmaLetEng/m.png");
Image n_img("./Entity/Textures/Symbols/SmaLetEng/n.png");
Image o_img("./Entity/Textures/Symbols/SmaLetEng/o.png");
Image p_img("./Entity/Textures/Symbols/SmaLetEng/p.png");
Image q_img("./Entity/Textures/Symbols/SmaLetEng/q.png");
Image r_img("./Entity/Textures/Symbols/SmaLetEng/r.png");
Image s_img("./Entity/Textures/Symbols/SmaLetEng/s.png");
Image t_img("./Entity/Textures/Symbols/SmaLetEng/t.png");
Image u_img("./Entity/Textures/Symbols/SmaLetEng/u.png");
Image v_img("./Entity/Textures/Symbols/SmaLetEng/v.png");
Image w_img("./Entity/Textures/Symbols/SmaLetEng/w.png");
Image x_img("./Entity/Textures/Symbols/SmaLetEng/x.png");
Image y_img("./Entity/Textures/Symbols/SmaLetEng/y.png");
Image z_img("./Entity/Textures/Symbols/SmaLetEng/z.png");
*/

Image zero_img("./Entity/Textures/Symbols/Numbers/0.png");
Image one_img("./Entity/Textures/Symbols/Numbers/1.png");
Image two_img("./Entity/Textures/Symbols/Numbers/2.png");
Image three_img("./Entity/Textures/Symbols/Numbers/3.png");
Image four_img("./Entity/Textures/Symbols/Numbers/4.png");
Image five_img("./Entity/Textures/Symbols/Numbers/5.png");
Image six_img("./Entity/Textures/Symbols/Numbers/6.png");
Image seven_img("./Entity/Textures/Symbols/Numbers/7.png");
Image eight_img("./Entity/Textures/Symbols/Numbers/8.png");
Image nine_img("./Entity/Textures/Symbols/Numbers/9.png");

Image apostrophe_img("./Entity/Textures/Symbols/Special/apostrophe.png");
Image colon_img("./Entity/Textures/Symbols/Special/colon.png");
Image comma_img("./Entity/Textures/Symbols/Special/comma.png");
Image exclamatio_img("./Entity/Textures/Symbols/Special/exclamation.png");
Image full_stop_img("./Entity/Textures/Symbols/Special/full_stop.png");
Image left_brackets_img("./Entity/Textures/Symbols/Special/left_brackets.png");
Image left_slash_img("./Entity/Textures/Symbols/Special/left_slash.png");
Image middle_slash_img("./Entity/Textures/Symbols/Special/middle_slash.png");
Image question_img("./Entity/Textures/Symbols/Special/question.png");
Image quotation_img("./Entity/Textures/Symbols/Special/quotation.png");
Image right_brackets_img("./Entity/Textures/Symbols/Special/right_brackets.png");
Image right_slash_img("./Entity/Textures/Symbols/Special/right_slash.png");
Image semicolon_img("./Entity/Textures/Symbols/Special/semicolon.png");
Image space_img("./Entity/Textures/Symbols/Special/space.png");

Image *pointer = &nine_img;


void Symbols::DefineSymbols()
{


    A_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/A.png");
    B_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/B.png");
    C_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/C.png");
    D_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/D.png");
    E_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/E.png");
    F_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/F.png");
    G_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/G.png");
    H_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/H.png");
    I_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/I.png");
    J_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/J.png");
    K_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/K.png");
    L_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/L.png");
    M_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/M.png");
    N_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/N.png");
    O_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/O.png");
    P_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/P.png");
    Q_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/Q.png");
    R_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/R.png");
    S_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/S.png");
    T_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/T.png");
    U_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/U.png");
    V_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/V.png");
    W_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/W.png");
    X_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/X.png");
    Y_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/Y.png");
    Z_img.rotate180deg("./Entity/Textures/Symbols/BigLetEng/Z.png");

    /*
    a_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/a.png");
    b_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/b.png");
    c_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/c.png");
    d_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/d.png");
    e_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/e.png");
    f_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/f.png");
    g_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/g.png");
    h_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/h.png");
    i_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/i.png");
    j_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/j.png");
    k_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/k.png");
    l_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/l.png");
    m_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/m.png");
    n_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/n.png");
    o_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/o.png");
    p_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/p.png");
    q_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/q.png");
    r_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/r.png");
    s_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/s.png");
    t_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/t.png");
    u_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/u.png");
    v_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/v.png");
    w_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/w.png");
    x_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/x.png");
    y_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/y.png");
    z_img.rotate180deg("./Entity/Textures/Symbols/SmaLetEng/z.png");
    */

     zero_img.rotate180deg("./Entity/Textures/Symbols/Numbers/0.png");
      one_img.rotate180deg("./Entity/Textures/Symbols/Numbers/1.png");
      two_img.rotate180deg("./Entity/Textures/Symbols/Numbers/2.png");
    three_img.rotate180deg("./Entity/Textures/Symbols/Numbers/3.png");
     four_img.rotate180deg("./Entity/Textures/Symbols/Numbers/4.png");
     five_img.rotate180deg("./Entity/Textures/Symbols/Numbers/5.png");
      six_img.rotate180deg("./Entity/Textures/Symbols/Numbers/6.png");
    seven_img.rotate180deg("./Entity/Textures/Symbols/Numbers/7.png");
    eight_img.rotate180deg("./Entity/Textures/Symbols/Numbers/8.png");
     nine_img.rotate180deg("./Entity/Textures/Symbols/Numbers/9.png");



      apostrophe_img.rotate180deg("./Entity/Textures/Symbols/Special/apostrophe.png");
      colon_img.rotate180deg("./Entity/Textures/Symbols/Special/colon.png");
      comma_img.rotate180deg("./Entity/Textures/Symbols/Special/comma.png");
      exclamatio_img.rotate180deg("./Entity/Textures/Symbols/Special/exclamation.png");
      full_stop_img.rotate180deg("./Entity/Textures/Symbols/Special/full_stop.png");
      left_brackets_img.rotate180deg("./Entity/Textures/Symbols/Special/left_brackets.png");
      left_slash_img.rotate180deg("./Entity/Textures/Symbols/Special/left_slash.png");
      middle_slash_img.rotate180deg("./Entity/Textures/Symbols/Special/middle_slash.png");
      question_img.rotate180deg("./Entity/Textures/Symbols/Special/question.png");
      quotation_img.rotate180deg("./Entity/Textures/Symbols/Special/quotation.png");
      right_brackets_img.rotate180deg("./Entity/Textures/Symbols/Special/right_brackets.png");
      right_slash_img.rotate180deg("./Entity/Textures/Symbols/Special/right_slash.png");
      semicolon_img.rotate180deg("./Entity/Textures/Symbols/Special/semicolon.png");

}

void Symbols::DrawLetter(Image &screen, Image &symbol, double deltaTime, int coord_x, int coord_y)
{
  Pixel pix;
  int xmax = screen.Width();
  int ymax = screen.Height();


  animation_counter += (deltaTime * 2);


  for(int y = 1 ; y < symbol.Height() ; ++y)
  {

    for(int x = 0 ; x < symbol.Width() ; ++x)
    {

      pix = symbol.GetPixel(x,y);

      if( int(pix.a) )
        screen.PutPixel( (x+coord_x)%xmax , (y+coord_y)%ymax , pix);


      //if (x + coord_x >= screen.Height() )
        //break;
    }


    //if (y + coord_y >= screen.Height() )
      //break;
  }

}

Image* Symbols::CharToImage(char letter)
{
  if (letter == 'A' || letter == 'a')
    return &A_img;

  if (letter == 'B' || letter == 'b')
    return &B_img;

  if (letter == 'C' || letter == 'c')
    return &C_img;

  if (letter == 'D' || letter == 'd')
    return &D_img;

  if (letter == 'E' || letter == 'e')
    return &E_img;


  if (letter == 'F' || letter == 'f')
    return &F_img;

  if (letter == 'G' || letter == 'g')
    return &G_img;

  if (letter == 'H' || letter == 'h')
    return &H_img;

  if (letter == 'I' || letter == 'i')
    return &I_img;

  if (letter == 'J' || letter == 'j')
    return &J_img;


  if (letter == 'K' || letter == 'k')
    return &K_img;

  if (letter == 'L' || letter == 'l')
    return &L_img;

  if (letter == 'M' || letter == 'm')
    return &M_img;

  if (letter == 'N' || letter == 'n')
    return &N_img;

  if (letter == 'O' || letter == 'o')
    return &O_img;


  if (letter == 'P' || letter == 'p')
    return &P_img;

  if (letter == 'Q' || letter == 'q')
    return &Q_img;

  if (letter == 'R' || letter == 'r')
    return &R_img;

  if (letter == 'S' || letter == 's')
    return &S_img;

  if (letter == 'T' || letter == 't')
    return &T_img;


  if (letter == 'U' || letter == 'u')
    return &U_img;

  if (letter == 'V' || letter == 'v')
    return &V_img;

  if (letter == 'W' || letter == 'w')
    return &W_img;

  if (letter == 'X' || letter == 'x')
    return &X_img;

  if (letter == 'Y' || letter == 'y')
    return &Y_img;

  if (letter == 'Z' || letter == 'z')
    return &Z_img;




  if (letter == '0')
    return &zero_img;

  if (letter == '1')
    return &one_img;

  if (letter == '2')
    return &two_img;

  if (letter == '3')
    return &three_img;

  if (letter == '4')
    return &four_img;

  if (letter == '5')
    return &five_img;

  if (letter == '6')
    return &six_img;

  if (letter == '7')
    return &seven_img;

  if (letter == '8')
    return &eight_img;

  if (letter == '9')
    return &nine_img;


  if (letter == '\'')
    return &apostrophe_img;

  if (letter == ':')
    return &colon_img;

  if (letter == ',')
    return &comma_img;

  if (letter == '!')
    return &exclamatio_img;

  if (letter == '.')
    return &full_stop_img;

  if (letter == '(')
    return &left_brackets_img;

  if (letter == '/')
    return &left_slash_img;

  if (letter == '|')
    return &middle_slash_img;

  if (letter == '?')
    return &question_img;

  if (letter == '"')
    return &quotation_img;

  if (letter == ')')
    return &right_brackets_img;

  if (letter == '\\')
    return &right_slash_img;

  if (letter == ';')
    return &semicolon_img;

  if (letter == ' ')
    return &space_img;

  return &question_img;
}

void Symbols::DrawWord(Image &screen, double deltaTime, int coord_x, int coord_y, std::string message)
{
  int shift_x = coord_x;
  int shift_y = coord_y;

  for ( int i = 0; i < message.size(); i++){

    pointer = CharToImage(message[i]);

    DrawLetter(screen, *pointer, deltaTime, shift_x % 1024, coord_y % 768);
    shift_x = shift_x + pointer->Width();
  }

}

void Symbols::DrawGlobalMessage(Image &screen, double deltaTime, int coord_x, int coord_y, std::string message, double &counter, bool &isActive )
{
  counter += deltaTime;
  if (counter > 7){
    counter = 0;
    isActive = false;
  }

  int shift_x = coord_x;
  int shift_y = coord_y;


  // Здесь будет код для белой полосы снизу
  for(int y = 0; y < 32; ++y)
  {
    for(int x = 0; x < 1024; ++x)
    {
      screen.PutPixel(x, y, {255,255,255,56} );
    }
  }

  //Печатаем сообщение по буквам
  for ( int i = 0; i < message.size(); i++){

    pointer = CharToImage(message[i]);

    DrawLetter(screen, *pointer, deltaTime, (shift_x + int(animation_counter) ) % 1024, coord_y % 768);
    shift_x = shift_x + pointer->Width();
  }



}
