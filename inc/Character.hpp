#pragma once
#include <SFML/Graphics.hpp>


namespace bnk {
    class Character {
    private:
        sf::Texture* m_texture = nullptr;
        sf::Sprite* m_sprite = nullptr;
        float m_w, m_h;
        float m_x, m_y;

    public:


        Character(const std::string& text, float x, float y, float w, float h) {
            m_w = w;
            m_h = h;
            m_x = x;
            m_y = y;
            m_texture = new sf::Texture;
            m_sprite = new sf::Sprite;
            m_texture->loadFromFile(text);
            m_sprite->setTexture(*m_texture);
            m_sprite->setTextureRect(sf::IntRect(0, 0, w, h));
            m_sprite->setPosition(x, y);
        }
        ~Character() {
            if(m_sprite != nullptr)
            delete m_sprite;
            if (m_sprite != nullptr)
            delete m_texture;
        }

        sf::Sprite* Get() { return m_sprite; }


        

        void update(sf::String Map[]) //функция обновления карты
        {

            m_sprite->setPosition(m_x, m_y); 
            interactionWithMap(Map);
        }
        void interactionWithMap(sf::String Map[])//функция взаимодействия с картой
        {

            for (int i = m_y / 40; i < (m_y + m_h) / 40; i++)
                for (int j = m_x / 40; j < (m_x + m_w) / 40; j++)
                {
                    if (Map[i][j] == 's') { 
                        Map[i][j] = ' ';
                    }
                }
        }

        void Move(float&currentframe, float t) {

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { 
                currentframe += 0.005 * t;
                if (currentframe > 4) currentframe -= 4;
                m_sprite->setTextureRect(sf::IntRect(80 * int(currentframe), 80, 80, 80));

                m_x += -0.1 * t;

            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                currentframe += 0.005 * t;
                if (currentframe > 4) currentframe -= 4;
                m_sprite->setTextureRect(sf::IntRect(80 * int(currentframe), 160, 80, 80));

                m_x += 0.1 * t;

            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                currentframe += 0.005 * t;
                if (currentframe > 4) currentframe -= 4;
                m_sprite->setTextureRect(sf::IntRect(80 * int(currentframe), 240, 80, 80));

                m_y += -0.1 * t; 

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                currentframe += 0.005 * t;
                if (currentframe > 4) currentframe -= 4;
                m_sprite->setTextureRect(sf::IntRect(80 * int(currentframe), 0, 80, 80));

                m_y += 0.1 * t;

            }
        }
    };
}