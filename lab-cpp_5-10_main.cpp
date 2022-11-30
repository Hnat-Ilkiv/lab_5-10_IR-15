#include <iostream>		// Підключення стандартної бібліотеки воду/виводу для коректної роботи може знадобитися додатковий ключ під час компіляції -lstdc++
#include "lab-cpp_5-10_class.h"	// Підключення власної бібліотеки з класами для обєктів файл і папка (методи і фукції додаються на моменті компіляції)

int main() {
	// Створення файлової системи
	Folder MD("mtd");											// Створення головної теци mtd
	Folder ROOT("root");						MD.addElement(ROOT);			// Створення в голоній теці теки root
	File dwm("dwm",".conf",2049);					ROOT.addElement(dwm);			// Створення в теці root файлу dwm.conf
	File arch("pacman",".out",58374);				ROOT.addElement(arch);			// Створення в теці root файлу pacman.out
	Folder HOME("home");						MD.addElement(HOME);			// Створення в головній теці теки home
	Folder USERNAME("User_Name");					HOME.addElement(USERNAME);		// Створення в теці home теки username
	Folder DOCUMENT("Document");					USERNAME.addElement(DOCUMENT);		// Створення в теці username теки documet
	File lab5class("lab-cpp_5-10_class", ".h", 2635);		DOCUMENT.addElement(lab5class);		// Створення в теці document файлу lab5class.h
	File lab5function("lab-cpp_5-10_function", ".cpp", 1907);	DOCUMENT.addElement(lab5function);	// Створення в теці document файлу lab5function.cpp
	File lab5main("lab-cpp_5-10_main", ".cpp", 881);		DOCUMENT.addElement(lab5main);		// Створення в теці document файлу lab5main.cpp
	Folder MUSIC("Music");						USERNAME.addElement(MUSIC);		// Створення в теці username теки music
	File lofimusic("lofi_4-am", ".flac", 1847392);			MUSIC.addElement(lofimusic);		// Створення в теці music файлу lofimusic.flac
	File bin("a",".out",128);					MD.addElement(bin);			// Створення в головній теці файл a.out

	MD.get_fileTree();	// Вивід дерева файлів від головної теки в термінал
	std::cout << std::endl;	// Пропуск одного рядка для більшої естетичності та читабильності
	MD.get_remoteFile();	// Вивід найдовшого файлового маршруту від головної теки в термінал

	return 0;
}
