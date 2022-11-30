#include <iostream> 		// Підключення стандартної бібліотеки воду/виводу 
#include "lab-cpp_5-10_class.h"	// Підключення власної бібліотеки з класами для о'бєктів файлу і тек 

// tab функція що виводить у термінал n-у кількість табів без переходу на новий рядочок
void tab(int n) { for (int i = 0; i < n; i++) std::cout << "\t"; }

File::File(std::string fileName, std::string fileExtension, int fileSize_byte)
{
	this->fileName = fileName;
	this->fileExtension = fileExtension;
	this->fileSize_byte = fileSize_byte;
}

Folder::Folder(std::string folderName) { this->folderName = folderName; }

void Folder::addElement(File & file) { fileList.push_back(&file); }

void Folder::addElement(Folder & folder) { folderList.push_back(&folder); }

void Folder::get_fileList(int n)
{
	for (int i = 0; i < fileList.size(); i++)
	{
		tab(n + 1);
		std::cout << fileList[i]->fileName << fileList[i]->fileExtension << std::endl;
	}
}

void Folder::get_fileTree()
{
	static int tabs = 0;
	tab(tabs);
	std::cout << folderName << std::endl;
	for (int i = 0; i < folderList.size(); i++)
	{
		tabs++;
		folderList[i]->get_fileTree();
		tabs--;
	}
	get_fileList(tabs);
}

int Folder::get_maxN_fromTree()
{
	static int n = 0;
	static int maxN = 0;
	for (int i = 0; i < folderList.size(); i++)
	{
		n++;
		folderList[i]->get_maxN_fromTree();
		if (n > maxN) maxN = n;
		n--;
	}
	return maxN;
}

void Folder::print_longRoude(int maxN, std::string nameFolder)
{
	static int n = 0;
	static std::vector <Folder*> longRoude;
	for (int i = 0; i < folderList.size(); i++)
	{
		n++;
		longRoude.push_back(folderList[i]);
		folderList[i]->print_longRoude(maxN, nameFolder);
		if (n == maxN)
		{
			for(int k = 0; k < longRoude[longRoude.size() - 1]->fileList.size(); k++)
			{
				std::cout << nameFolder << "/";
				for(int j = 0; j < longRoude.size(); j++)
				{
					std::cout << longRoude[j]->folderName << "/";
				}
				std::cout << longRoude[longRoude.size() - 1]->fileList[k]->fileName 
					<< longRoude[longRoude.size() - 1]->fileList[k]->fileExtension 
					<< std::endl;
			}
		}
		n--;
		longRoude.pop_back();
	}
}

void Folder::get_remoteFile()
{
	int maxN = get_maxN_fromTree();
	print_longRoude(maxN, folderName);
}
