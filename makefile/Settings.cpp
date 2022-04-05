#include "include.h"

bool EndGame = false;
bool Full = false;
String Language = "Russian";
String After_Befor = "Befor";

int configurations() {

	ofstream config_writing("DATA/config/config.ini", ios::binary);
	ifstream config_load("DATA/config/config.ini", ios::binary);
	config_load.seekg(0, ios_base::end);
	int size = config_load.tellg();
	if (size == 0)
		{
			config_writing.write((char*)&EndGame, sizeof(bool));
			config_writing.write((char*)&Full, sizeof(bool));
			config_writing.write((char*)&Language, sizeof(String));
			config_writing.write((char*)&After_Befor, sizeof(String));
			config_writing.close();
			window.close();
		}

	if (config_load.is_open()) {
		while (config_load.read((char*)&EndGame, sizeof(bool))); {
		}
		while (config_load.read((char*)&Full, sizeof(bool)));
		while (config_load.read((char*)&Language, sizeof(String)));
		while (config_load.read((char*)&After_Befor, sizeof(String)));
		config_load.close();
	}
	return 0;
}
//Author: IPOleksenko