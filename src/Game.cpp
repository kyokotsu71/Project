#include <Game.hpp>

namespace bnk
{
		Game::~Game() {
			if (m_window != nullptr)
				delete m_window;
		}

		void Game::SetCaption(const std::string& caption) {
			m_caption = caption;
		}

		void Game::SetResolution(int width, int height) {
			m_width = width;
			m_height = height;
		}

		void Game::Setup() {
			m_window = new sf::RenderWindow(sf::VideoMode(m_width, m_height), m_caption);
		}

		void Game::Run() {

			std::vector<bnk::Ball*> balls;

			balls.emplace_back(new bnk::Ball({ 0, 0 }, { 150, 150 }, 80, 50, sf::Color::Red));
			balls.emplace_back(new bnk::Ball({ 0, 200 }, { 150, 150}, 50, 6, sf::Color::Yellow));

			 
			sf::Clock timer;
			double dt = 0;

			while (m_window->isOpen())
			{
				sf::Event event;
				while (m_window->pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						m_window->close();
				}

				sf::Time dt = timer.restart();

				for (int i = 0; i < balls.size(); i++) {

					Point p = balls[i]->GetPosition();
					float r = balls[i]->Radius();

					if (p.y+2*r >= m_height) {
						Vector v = balls[i]->GetVelocity();
						balls[i]->SetVelocity({0, 0});
					}
					if (p.x+2*r >= m_width) {
						Vector v = balls[i]->GetVelocity();
						balls[i]->SetVelocity({ 0, 0 });
					}
					
					if (p.y <= 0) {
						Vector v = balls[i]->GetVelocity();
						balls[i]->SetVelocity({ v.x, -v.y });
					}
					if (p.x <= 0) {
						Vector v = balls[i]->GetVelocity();
						balls[i]->SetVelocity({ -v.x, v.y });
					}
				}

				for (int i = 0; i < balls.size(); i++)
					balls[i]->Move(dt.asSeconds());

				m_window->clear();
				for(int i = 0; i < balls.size(); i++)
					m_window->draw(*balls[i]->Get());
				m_window->display(); 

			}
			for (int i = 0; i < balls.size(); i++)
				delete balls[i];
		}

}