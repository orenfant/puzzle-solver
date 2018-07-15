#include <iostream>

#include "class_nono.hpp"

int main(int argc, char ** argv)
{
	Board brd_a(2,2);
	
	std::cout << "The Board..." << std::endl;

	brd_a.assign_cell(2, 2, black);
	brd_a.assign_cell(0, 0, black);
	brd_a.assign_cell(1, 1, black);
	brd_a.show_cmd();

	Board brd_b(0, 0);
	brd_b.load_file("sample-board.txt");
	brd_b.show_cmd();
	
	return 0;

}
