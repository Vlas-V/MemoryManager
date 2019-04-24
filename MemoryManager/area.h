#include "pch.h"

#ifndef dllist_H
#define dllist_H

struct dllist
{
	std::string name;
	unsigned short beg;		// Memory index of the beginning of a file 
	unsigned short size;

	struct dllist* prev;
	struct dllist* next;

	dllist()
	{
		this->name = nullptr;
		this->beg = 0;
		this->size = 0;

		prev = NULL;
		next = NULL;
	}

	
	dllist(unsigned short beg_index, unsigned short size)
	{
		this->name = nullptr;
		this->beg = beg_index;
		this->size = size;

		prev = NULL;
		next = NULL;
	}


	dllist(std::string name, unsigned short beg_index, unsigned short size)
	{
		this->name = name;
		this->beg = beg_index;
		this->size = size;

		prev = NULL;
		next = NULL;
	}




	// ?? do i need this function??
	// Create an empty dllist
	dllist* create();

	// Finds the node with the closest to the provided parameter size field value 
	dllist* find_closest_min(int);

	// Shrinks the size and position of the node 
	void shrink(int);

	// Add (insert) a new element into dllist
	void add_dllist(unsigned short beg_index, unsigned short size);

	void add_file(std::string file_name, unsigned short beg_index, unsigned short size);

	void delete_dllist();

	// Delete an element for dllist
	void delete_element(std::string file_name);

	// Delete a whole dllist
	void delete_list();

	// Retrive data from file
	void from_file(std::string file_name, bool with_file_name);

	// Write data back to file
	void to_file(std::string file_name);

	void show_list_info();
};


dllist* insert_file(dllist* head, std::string name, unsigned short beg_index, unsigned short size);

dllist* insert_dllist(dllist* head, unsigned short beg_index, unsigned short size);

bool delete_file(dllist* head, std::string name);

bool delete_dllist(dllist* head, unsigned short beg_index);

bool shrink_dllist(dllist* head, unsigned short beg_index, unsigned short number);

dllist find_closest_min(dllist* head, unsigned short size);

#endif // dllist_H