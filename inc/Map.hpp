#include <SFML/Graphics.hpp>
#include <Game.hpp>
const int heightmap = 25;
const int widthmap = 25;
sf::String Map[heightmap] = {
	"0000000000000000000000000",
	"0                       0",
	"0                       0",
	"0                s      0",
	"0     s                 0",
	"0                       0",
	"0             s         0",
	"0                       0",
	"0                       0",
	"0         s        s    0",
	"0                       0",
	"0                       0",
	"0               s       0",
	"0    s                  0",
	"0                       0",
	"0                       0",
	"0       s               0",
	"0                       0",
	"0                s      0",
	"0     s                 0",
	"0                       0",
	"0          s            0",
	"0                       0",
	"0                       0",
	"0000000000000000000000000",
};
namespace bnk {
	class MapM {
	private:
		sf::Texture* m_maptexture = nullptr;
		sf::Sprite* m_mapsprite = nullptr;
	public:
		MapM(std::string file) {
			m_maptexture = new sf::Texture;
			m_mapsprite = new sf::Sprite;
			m_maptexture->loadFromFile(file);
			m_mapsprite->setTexture(*m_maptexture);
		};
		~MapM(){
			delete m_maptexture;
			delete m_mapsprite;
		};


		sf::Sprite* GetM() { return m_mapsprite; }

		void MapDraw(int i, int j) {
			if (Map[i][j] == ' ')  m_mapsprite->setTextureRect(sf::IntRect(0, 0, 40, 40));
			if (Map[i][j] == '0')  m_mapsprite->setTextureRect(sf::IntRect(40, 0, 40, 40));
			if (Map[i][j] == 's')  m_mapsprite->setTextureRect(sf::IntRect(80, 0, 40, 40));
			m_mapsprite->setPosition(j * 40, i * 40);
		}


	};
}