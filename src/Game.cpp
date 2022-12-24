#include<Game.hpp>
#include<SFML/Graphics.hpp>
#include<Character.hpp>
#include<Map.hpp>
#include <iostream>
#include <view.hpp>


namespace bnk {


    Game::Game() {};
    Game::~Game() {};
    void Game::SetResolution(int width, int height) {
        m_width = width;
        m_height = height;
    }

    void Game::SetCaption(std::string caption) {
        m_caption = caption;
    }
    void Game::Setup() {
        m_window = new sf::RenderWindow(sf::VideoMode(m_width, m_height), m_caption);
    }
    void Game::Run() {
        MapM* map = new MapM("C:/Git/Project/images/Map.png");//файл с текстурами карты
        Character* hero = new Character("C:/Git/Project/images/obj.png", 100, 100, 80, 80);//создание персонажа
        view.reset(sf::FloatRect(0, 0, 400, 400)); //область камеры при создании
        sf::Clock clock;
        float currentframe = 0;

        while (m_window->isOpen()) {
            float t = m_clock.getElapsedTime().asMicroseconds();
            m_clock.restart();
            t = t / 800;

            sf::Event event;
            while (m_window->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    m_window->close();
            }

            hero->Move(currentframe, t);// движение персонажа
            hero->update(Map);
            viewmap(t);
            changeview();

            m_window->setView(view);
            m_window->clear(sf::Color(128, 106, 89));// color - цвет за границей окна

            //генеграция карты
            for (int i = 0; i < heightmap; i++)
                for (int j = 0; j < widthmap; j++)
                {
                    map->MapDraw(i, j);
                    m_window->draw(*map->GetM());
                }

            //генерация персонажа
            m_window->draw(*hero->Get());

            m_window->display();
        }
    };
}
