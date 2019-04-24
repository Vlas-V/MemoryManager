#include "pch.h"


Area* insert_file(Area* head, std::string name, unsigned short beg_index, unsigned short size)
{
	// Allocate memory for a the new node
	Area* new_node = new Area(name, beg_index, size);
	
	// Check if everything's okay
	if (new_node == NULL)
		return NULL;
	
	// Insert the node into the beggining of the list
	new_node->prev = NULL;
	new_node->next = head;

	head->prev = new_node;
	head = new_node;

	return head;
}

Area* insert_area(Area* head, unsigned short beg_index, unsigned short size)
{
	// Allocate memory for a the new node
	Area* new_node = new Area(beg_index, size);

	// Check if everything's okay
	if (new_node == NULL)
		return NULL;

	// Insert the node into the beggining of the list
	new_node->prev = NULL;
	new_node->next = head;

	head->prev = new_node;
	head = new_node;

	return head;
}

bool delete_file(Area* head, std::string name)
{
	// Deletes a unique node with a provided unique name

	Area* trav;
	trav = head;

	while (trav)
	{
		if (trav->name == name)
		{ 
			// Delete the node
			trav->prev->next = trav->next;
			trav->next->prev = trav->prev;

			// Free the allocated memory
			delete trav;

			return true;
		}
		trav = trav->next;
	}

	return false;
}

bool delete_area(Area* head, unsigned short beg_index)
{

	Area* trav;
	trav = head;

	while (trav)
	{
		if (trav->beg == beg_index)
		{
			// Delete the node
			trav->prev->next = trav->next;
			trav->next->prev = trav->prev;

			// Free the allocated memory
			delete trav;

			return true;
		}
		trav = trav->next;
	}

	return false;
}

bool shrink_area(Area* head, unsigned short beg_index, unsigned short number)
{
	Area* trav;
	trav = head;

	while (trav)
	{
		if (trav->beg == beg_index)
		{
			trav->beg -= number;
			trav->size -= number;

			return true;
		}
	}

	return false;
}

// Returns an index of the of smallest (but big enought for the file) area
// Returns 0 if the area hasn't been found 
Area find_closest_min(Area* head, unsigned short size)
{
	unsigned short closest_min = INT_MAX;
	unsigned short index = 0;

	Area* trav = head;
	while (trav)
	{
		if (trav->size >= size && trav->size < closest_min)
		{
			closest_min = trav->size;
			index = trav->beg;
		}

		trav = trav->next;
	}

	if (closest_min == INT_MAX)
	{
		return Area();
	}
	
	trav = head;
	while (trav)
	{
		if (trav->size == closest_min)
		{
			return *(trav);
		}

		trav = trav->next;
	}
}



void Area::from_file(std::string file_name, bool with_file_name)
{
	std::ifstream infile(file_name);
	if (!infile.is_open())
	{
		std::cout << "Couldn't open " + file_name +  " for reading data\n";
		infile.close();
		return;
	}
	
	std::string name = nullptr;
	unsigned short beg;
	unsigned short size;

	if (with_file_name)
	{
		while (infile.peek() != EOF)
		{
			infile >> name;
			infile >> beg;
			infile >> size;

			this->add_file(name, beg, size);
		}
	}
	else
	{
		while (infile.peek() != EOF)
		{
			infile >> beg;
			infile >> size;

			this->add_area(beg, size);
		}
	}
	

	infile.close();
}

void Area::to_file(std::string file_name)
{
	std::ofstream outfile(file_name);
	if (!outfile.is_open())
	{
		std::cout << "Couldn't open " + file_name + " for saving data\n";
		outfile.close();
		return;
	}

	Area* trav = this;

	while (trav)
	{
		if (&(trav->name) != nullptr)
		 outfile << trav->name;
		outfile << trav->beg;
		outfile << trav->size;
		outfile << '\n';

		trav = trav->next;
	}


	outfile.close();
}

