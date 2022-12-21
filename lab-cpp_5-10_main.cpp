#include <iostream>
#include "lab-cpp_5-10_class.h"

int main() {
	Folder MD("mtd");
	Folder ROOT("root");
	Folder HOME("home");
	Folder USERNAME("User_Name");
	Folder DOCUMENT("Document");
	Folder MUSIC("Music");

	File dwm("dwm",".conf",2049);
	File arch("pacman",".out",58374);
	File lab5class("lab-cpp_5-10_class", ".h", 2635);
	File lab5function("lab-cpp_5-10_function", ".cpp", 1907);
	File lab5main("lab-cpp_5-10_main", ".cpp", 881);
	File lofimusic("lofi_4-am", ".flac", 1847392);
	File bin("a",".out",128);
	
	MD.AddElement(ROOT);
	ROOT.AddElement(dwm);
	ROOT.AddElement(arch);
	MD.AddElement(HOME);
	HOME.AddElement(USERNAME);
	USERNAME.AddElement(DOCUMENT);
	DOCUMENT.AddElement(lab5class);
	DOCUMENT.AddElement(lab5function);
	DOCUMENT.AddElement(lab5main);
	USERNAME.AddElement(MUSIC);
	MUSIC.AddElement(lofimusic);
	MD.AddElement(bin);

	MD.GetFileTree();
	std::cout << std::endl;
	MD.GetLongerFileRoude();

	return 0;
}
