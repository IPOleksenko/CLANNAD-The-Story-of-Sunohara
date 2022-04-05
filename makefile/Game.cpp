#include "include.h"

int main();
class game_option_menu {
public:
	int gom() {
		//Window
		Texture Imagebackground;
		if (EndGame == false)Imagebackground.loadFromFile("DATA/Texture/icon/background_sattings_befor.png");
		if (EndGame == true)Imagebackground.loadFromFile("DATA/Texture/icon/background_sattings_after.png");
		Sprite SpriteBackground;
		SpriteBackground.setTexture(Imagebackground);
		SpriteBackground.setScale(
			window.getSize().x / SpriteBackground.getGlobalBounds().width,
			window.getSize().y / SpriteBackground.getGlobalBounds().height);

		while (window.isOpen()) {
			Event event;
			while (window.pollEvent(event)) {
				if (event.type == Event::Closed)
					window.close();
			}
			window.clear();
			window.draw(SpriteBackground);
			window.display();
		}
		return 0;
	}
};
class GAME : public game_option_menu{
public:
	game_option_menu gom;
	void NewGame() 
	{
		gom.gom();
		return;
	}

	void Continue() 
	{
		gom.gom();
		return;
	}

	void Settings() 
	{
		gom.gom();
		return;
	}

	void Achievements() 
	{
		gom.gom();
		return;
	}
};
//Author: IPOleksenko