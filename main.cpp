#include<Game.hpp>

int main()
{
    bnk::Game game;
    game.SetResolution(1000, 1000);// разрешение
    game.SetCaption("123");//заголовок окна
    game.Setup();//установка
    game.Run();//запуск

    return 0;
}
 