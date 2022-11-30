#include <vector> // Підключення додаткового типу даних вектор

class File {
	public:
		std::string fileName;
		std::string fileExtension;
		int fileSize_byte;

		File(std::string fileName, std::string fileExtension, int fileSize_byte);

};
class Folder{
	public:
		std::string folderName;
		std::vector <File*> fileList;
		std::vector <Folder*> folderList;

		Folder(std::string folderName);

		void addElement(File & file);
		void addElement(Folder & folder);

		void get_fileList(int n);
		void get_fileTree();
		int get_maxN_fromTree();
		void print_longRoude(int maxN, std::string nameFolder);
		void get_remoteFile();
};
