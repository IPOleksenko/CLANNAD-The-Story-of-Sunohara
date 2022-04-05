#include "include.h"
#include "Game.cpp"

int menu() {
	//Set background
	Image Imagebackground;
	if (EndGame == false)Imagebackground.loadFromFile("DATA/Texture/icon/background_befor.png");
	if (EndGame == true)Imagebackground.loadFromFile("DATA/Texture/icon/background_after.png");

	Texture Texturebackground;
	Texturebackground.loadFromImage(Imagebackground);

	Sprite SpriteBackground;
	SpriteBackground.setTexture(Texturebackground);
	SpriteBackground.setScale(
		window.getSize().x / SpriteBackground.getGlobalBounds().width,
		window.getSize().y / SpriteBackground.getGlobalBounds().height);

	Text Title;
	Font Font_Title;
	Font_Title.loadFromFile("DATA/Font/CaviarDreamsItalic.ttf");
	Title.setFont(Font_Title);
	Title.setString("\t\tCLANNAD \n~The Story of Sunohara~");
	Title.setCharacterSize((SizeWindow / 100) * 3.7);
	Title.setFillColor(Color::Red);
	Title.setPosition((SizeWindow / 100) * 1.8, (SizeWindow / 100) * 2);
	//button
	String BUTT[5] = { "NewGame", "Continue", "Settings", "Achievements", "Exit" };
	Texture NewGame, Continue, Settings, Achievements, Exit;
	Texture BUTTONS[5] = { ref(NewGame),ref(Continue), ref(Settings), ref(Achievements), ref(Exit) };
	for (int i = 0; i < 5; i++) if (!BUTTONS[i].loadFromFile("DATA/Texture/Buttons/" + BUTT[i] + "_" + After_Befor + "_" + Language + ".png")) return EXIT_FAILURE;

	Sprite NewGame_sp, Continue_sp, Settings_sp, Achievements_sp, Exit_sp;
	Sprite BUTTONS_sp[5] = { ref(NewGame_sp), ref(Continue_sp), ref(Settings_sp), ref(Achievements_sp), ref(Exit_sp) };
	for (int i = 0; i < 5; i++) {
		BUTTONS_sp[i].setTexture(BUTTONS[i]);
		BUTTONS_sp[i].scale(Vector2f((SizeWindow / 10000.f), (SizeWindow / 10000.f)));
		BUTTONS_sp[i].setPosition((SizeWindow / 50) * 1.8, (SizeWindow / 15) + (SizeWindow / 15) * (1 + i));
	}
	//Window
	GAME GAME;

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(SpriteBackground);
		window.draw(Title);
		for (int i = 0; i < 5; i++) window.draw(BUTTONS_sp[i]);

		for (int i = 0; i < 5; i++) if (IntRect(BUTTONS_sp[i].getGlobalBounds()).contains(Mouse::getPosition(window)))
		{
			BUTTONS[i].loadFromFile("DATA/Texture/Buttons/" + BUTT[i] + After_Befor + "_" + Language + ".png");
			if (event.type == Event::MouseButtonReleased) {
				if (IntRect(BUTTONS_sp[0].getGlobalBounds()).contains(Mouse::getPosition(window))) { GAME.NewGame(); }
				if (IntRect(BUTTONS_sp[1].getGlobalBounds()).contains(Mouse::getPosition(window))) { GAME.Continue(); }
				if (IntRect(BUTTONS_sp[2].getGlobalBounds()).contains(Mouse::getPosition(window))) { GAME.Settings(); }
				if (IntRect(BUTTONS_sp[3].getGlobalBounds()).contains(Mouse::getPosition(window))) { GAME.Achievements(); }
				if (IntRect(BUTTONS_sp[4].getGlobalBounds()).contains(Mouse::getPosition(window))) { window.close(); }
				
				if (!IntRect(BUTTONS_sp[i].getGlobalBounds()).contains(Mouse::getPosition(window))) 
					{ BUTTONS[i].loadFromFile("DATA/Texture/Buttons/"+ BUTT[i] + After_Befor + "_" + Language + ".png"); 
						BUTTONS_sp[i].setColor(Color::White); }
			}
		}
		window.display();
	}
	return 0;
}
//Author: IPOleksenko