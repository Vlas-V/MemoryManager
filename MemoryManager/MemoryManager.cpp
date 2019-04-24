// MemoryManager

#include "pch.h"

Area* alloc_areas;
Area* free_areas;

int main()
{
	// Retrive data for files
	alloc_areas->from_file("allocated.txt");
	free_areas->from_file("free.txt");


	// We have a pool of memory with capacity of 360 KB (368_640 B)

	// We can add and delete (maybe read and write?) files into the memory

	// Size of a file must be in range from 18 B to 32 B


	

	// How to write 
	// 2. Free memory areas (sote in a dllist)
	//[3.] List of files and their places in memory


	// TODO
	// + Build API 
	// - Create dllists for files or memory allocation management
	// - Ensure usage only of unique names 


	// Retrive information from files

	
	// Use commands for this:

	// 1. add [file's name] [number of bytes]
	// 2. delete [file's name] [[number of bytes]]


	std::string command;
	bool exit = false;

	while (!exit)
	{
		// Prompt user for input
		std::cout << ">";
		std::cin >> command;
		exit = controller(command);
	}


	// Save information to files
	alloc_areas->to_file("allocated.txt");
	free_areas->to_file("free.txt");
	
	// Free memory
	alloc_areas->delete_list();
	free_areas->delete_list();
}