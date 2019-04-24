#include "pch.h"

bool controller(std::string command)
{

	std::string command;
	std::string name;
	std::string size_str;
	int size;

	// Acting according to the command
	if (command == "exit")
	{
		return true;
	}
	else if (command == "help")
	{
		std::cout << "Usage: command name size" << std::endl;
		std::cout << "Commands:\n add\n delete\n";
		std::cout << "Size must be represented in bytes and range from 18 to 36 B included." << std::endl;
	}
	else if (command == "add")
	{
		std::cin >> name;
		std::cin >> size_str;

		// Ensure proper size parsing
		try
		{
			size = std::stoi(size_str);
		}
		catch (...)
		{
			std::cout << "The size in invalid." << std::endl;
		}

		// Ensure proper size range
		if (size < 18 || size > 32)
		{
			std::cout << "Size must be in range from 18 to 32 included." << std::endl;
		}


		// Maniputation with the list of free areas


		Area closest = find_closest_min(free_areas, size);
		// Check if the proper area has been found 
		if (closest.prev == NULL && closest.next == NULL)
		{
			std::cout << "Not enough memory to add the file!" << std::endl;
		}

		// Save the index of the free area
		unsigned short free_index = closest->beg;

		// Delete or shrink the free area
		if ( == size)
		{
			delete_area();
		}
		else
		{
			closest->shrink(size);
		}

		alloc_areas->add_file(name, free_index, size);
		std::cout << "The file has been added on disk!" << std::endl;
	}
	else if (command == "delete")
	{
		std::cin >> name;


		std::cout << "The file has been deleted from disk!" << std::endl;
	}
	else if (command == "show")
	{
		std::cin >> name;
		if (name == "allocated")
		{
			alloc_areas->show_list_info();
		}
		else if (name == "free")
		{
			free_areas->show_list_info();
		}
		else
		{
			std::cout << "Invalid command-line argument. Type 'help' for more information" << std::endl;
		}
	}
	else
	{
		std::cout << "Command is not found. Type 'help' for more information." << std::endl;
	}

	return false;
}