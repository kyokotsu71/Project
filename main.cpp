#include<Game.hpp>

int main()
{
    bnk::Game game;
    game.SetResolution(1000, 1000);
    game.SetCaption("123");
    game.Setup();

    game.Run();
     
    return 0;
}