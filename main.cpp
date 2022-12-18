#include<Game.hpp>

int main()
{
    bnk::Game game;
    game.SetResolution(800, 800);
    game.SetCaption("123");
    game.Setup();

    game.Run();
     
    return 0;
}