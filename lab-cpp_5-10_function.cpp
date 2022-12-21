#include <iostream>
#include "lab-cpp_5-10_class.h"

void tab(int tabs) { for (int i = 0; i < tabs; i++) std::cout << "\t"; }

File::File(std::string file_name_, std::string file_extension_, int file_size_by_bytes_)
{
	this->file_name_ = file_name_;
	this->file_extension_ = file_extension_;
	this->file_size_by_bytes_ = file_size_by_bytes_;
}

Folder::Folder(std::string folder_name_) { this->folder_name_ = folder_name_; }

void Folder::AddElement(File& file) { file_list_.push_back(&file); }

void Folder::AddElement(Folder& folder) { folder_list_.push_back(&folder); }

void Folder::GetFileList(int tabs)
{
	for (int i = 0; i < file_list_.size(); i++)
	{
		tab(tabs + 1);
		std::cout << file_list_[i]->file_name_ << file_list_[i]->file_extension_ << std::endl;
	}
}

void Folder::GetFileTree()
{
	static int tabs = 0;
	tab(tabs);
	std::cout << folder_name_ << std::endl;
	for (int i = 0; i < folder_list_.size(); i++)
	{
		tabs++;
		folder_list_[i]->GetFileTree();
		tabs--;
	}
	GetFileList(tabs);
}

int Folder::GetMaxTabFromTree()
{
	static int tabs = 0;
	static int max_tab = 0;
	for (int i = 0; i < folder_list_.size(); i++)
	{
		tabs++;
		folder_list_[i]->GetMaxTabFromTree();
		if (tabs > max_tab) max_tab = tabs;
		tabs--;
	}
	return max_tab;
}

void Folder::PrintLongRoudes(int max_tab, std::string folder_name)
{
	static int tabs = 0;
	static std::vector <Folder*> longRoude;
	for (int i = 0; i < folder_list_.size(); i++)
	{
		tabs++;
		longRoude.push_back(folder_list_[i]);
		folder_list_[i]->PrintLongRoudes(max_tab, folder_name);
		if (tabs == max_tab)
		{
			for(int k = 0; k < longRoude[longRoude.size() - 1]->file_list_.size(); k++)
			{
				std::cout << folder_name << "/";
				for(int j = 0; j < longRoude.size(); j++)
				{
					std::cout << longRoude[j]->folder_name_ << "/";
				}
				std::cout << longRoude[longRoude.size() - 1]->file_list_[k]->file_name_ 
					<< longRoude[longRoude.size() - 1]->file_list_[k]->file_extension_ 
					<< std::endl;
			}
		}
		tabs--;
		longRoude.pop_back();
	}
}

void Folder::GetLongerFileRoude()
{
	int max_tab = GetMaxTabFromTree();
	PrintLongRoudes(max_tab, folder_name_);
}
