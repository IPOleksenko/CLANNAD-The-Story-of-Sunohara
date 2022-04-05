#include "include.h"

int configurations();
RenderWindow window(VideoMode(1366, 768, 32), "CLANNAD ~The Story of Sunohara~", Style::None | Style::Titlebar);
int menu();

int SizeWindow = sqrt(pow(window.getSize().x, 2) + pow(window.getSize().y, 2));

int load_screen() {
	//Set background
	Texture Imagebackground, load_image, load_text;
	if (EndGame == false)Imagebackground.loadFromFile("DATA/Texture/icon/background_befor.png");
	if (EndGame == true)Imagebackground.loadFromFile("DATA/Texture/icon/background_after.png");
	load_image.loadFromFile("DATA/Texture/icon/loading.png");
	load_text.loadFromFile("DATA/Texture/icon/loading....png");

	Sprite SpriteBackground, load_sprite, load_text_sprite;
	SpriteBackground.setTexture(Imagebackground);
	SpriteBackground.setScale(
		window.getSize().x / SpriteBackground.getGlobalBounds().width,
		window.getSize().y / SpriteBackground.getGlobalBounds().height);

	load_sprite.setTexture(load_image);
	load_sprite.setScale(Vector2f((SizeWindow / 2500.f), (SizeWindow / 2500.f)));
	FloatRect load_spriteRect = load_sprite.getLocalBounds();
	load_sprite.setPosition((SizeWindow / 100) * 20.f, (SizeWindow / 100) * 20.f);
	load_sprite.setOrigin(load_spriteRect.left + load_spriteRect.width / 2.0f,
		load_spriteRect.top + load_spriteRect.height / 2.0f);

	load_text_sprite.setTexture(load_text);
	load_text_sprite.setPosition((SizeWindow / 100) * 4.5f, (SizeWindow / 100) * 14.5f);
	load_text_sprite.setScale(Vector2f((SizeWindow / 2000.f), (SizeWindow / 2000.f)));
	while(window.isOpen()) {
		load_sprite.rotate(load_sprite.getRotation() + 1);

		window.draw(SpriteBackground);
		window.draw(load_sprite);
		window.draw(load_text_sprite);
		window.display();
	}
	return 0;
}

int main()
{
	configurations();

	if (Full == true) {
		window.create(VideoMode(), "CLANNAD ~The Story of Sunohara~", Style::Fullscreen | sf::Style::Titlebar);}
	else if (Full == false) {
		window.create(VideoMode(1366, 768, 32), "CLANNAD ~The Story of Sunohara~", Style::None | Style::Titlebar);
	}
	else { window.close(); }
	//Set icon window
	Image icon;
	if (!icon.loadFromFile("DATA/Texture/icon/icon.png")) {return EXIT_FAILURE;}
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window.setVerticalSyncEnabled(true);
	//std::thread Thread(load_screen);
	//Thread.detach();
	menu();
	return 0;
}
//Author: IPOleksenko