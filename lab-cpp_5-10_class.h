#include <vector>

class File {
	public:
		std::string file_name_;
		std::string file_extension_;
		int file_size_by_bytes_;

		File(std::string file_name_, std::string file_extension_, int file_size_by_bytes_);
};

class Folder{
	public:
		std::string folder_name_;
		std::vector <File*> file_list_;
		std::vector <Folder*> folder_list_;

		Folder(std::string folder_name_);

		void AddElement(File& file);
		void AddElement(Folder& folder);

		void GetFileList(int tabs);
		void GetFileTree();
		int GetMaxTabFromTree();
		void PrintLongRoudes(int max_tab, std::string folder_name);
		void GetLongerFileRoude();
};
