#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Character.hpp>
namespace bnk {
    class Game {
    private:
        sf::RenderWindow* m_window = nullptr;
        int m_width;
        int m_height;
        std::string m_caption;
        sf::Clock m_clock;
    public:
        Game();

        ~Game();

        void SetResolution(int width, int height);

        void SetCaption(std::string caption);

        void Setup();

        void Run();
    };
}