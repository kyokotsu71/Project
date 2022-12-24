#pragma once
#include<SFML/Graphics.hpp>
sf::View view; // ������

// ��������� ��������� ������ � ��������� ��������� ������
void getplayercoord(float x, float y) {  
	view.setCenter(x + 100, y);
}

//����������� ������ �� �����
void viewmap(float t) { 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		view.move(0.25 * t, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		view.move(0, 0.25 * t);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		view.move(-0.25 * t, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		view.move(0, -0.25 * t);
	}
}

//����������� � ��������� ������
void changeview() {


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		view.zoom(1.0010f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
		view.zoom(0.9990f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		view.setSize(400, 400);
	}



}