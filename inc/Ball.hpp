#pragma once
#include <SFML/Graphics.hpp>

namespace bnk
{
	struct Point{
		float x; 
		float y;
	};

	struct Vector{
		float x;
		float y;
	};

	class Ball{
	private:
		Point m_p0;
		Vector m_velocity;
		float m_r;
		sf::CircleShape* m_shape;
		int m_top;
	public:
		
		Ball(Point p0, Vector v, float R, int top, sf::Color color) {
			m_p0 = p0;
			m_velocity = v;
			m_r = R;
			m_top = top;
			m_shape = new sf::CircleShape(m_r, top);
			m_shape->setOrigin(0, 0);
			m_shape->setFillColor(color);

		}

		~Ball() {
			delete m_shape;
		}

		void Move(double dt) {
			m_p0.x += m_velocity.x * dt; 
			m_p0.y += m_velocity.y * dt;
			m_shape->setPosition(m_p0.x, m_p0.y);
		}

		sf::CircleShape* Get() { return m_shape; }

		void SetVelocity(Vector v) {
			m_velocity = v;
		}

		Point GetPosition() { return m_p0; }
		Vector GetVelocity() { return m_velocity; }

		float Radius() { return m_r; }
	};
	



}