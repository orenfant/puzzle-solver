#include <iostream>
#include <fstream>
#include <string>

#include "class_nono.hpp"

Board::Board(int arg_height, int arg_width){
	resize(arg_height, arg_width);
}

void Board::resize(int arg_height, int arg_width){
	height = arg_height;
	width = arg_width;

	vec_brd.resize(height);
	for(auto itr = vec_brd.begin(); itr != vec_brd.end(); ++itr) {
        (*itr).resize(width, white);
    }
}

int Board::load_file(std::string filename)
{
	std::ifstream ifs(filename);

	if(ifs.fail()){
		std::cerr << "Fail to open " << filename << std::endl;
		return -1;
	}

	bool found_height = false;
	bool found_width = false;
	int file_height, file_width;
	std::string str;
	int count_height = 0;
	while(getline(ifs, str)){
		if(str[0] == '#') continue;

		if(found_height && found_width){
			// 3行目以降の処理
			int count_width = 0;
			for(int i = 0; i < str.size(); i++){
				char tmp_char = str[i];
				if(tmp_char == '0'){
					vec_brd[count_height][count_width] = white;
					count_width++;
				} else if(tmp_char == '1'){
					vec_brd[count_height][count_width] = black;
					count_width++;
				}
			}
			count_height++;
		} else if(found_height == false){
			// 1行目の処理（高さを取得）
			file_height = std::stoi(str);
			found_height = true;
		} else {
			// 2行目の処理（横の幅を取得）
			file_width = std::stoi(str);
			found_width = true;
			resize(file_height, file_width);
		}
		
	}

	return 0;
}


void Board::assign_cell(int y, int x, Color arg_color)
{
	if((y < 0 || y >= height) || (x < 0 || x>= width) ){
		std::cerr << "Invalid coordinates! (y=" << y << ", x=" << x << ")" << std::endl;
		return;
	}
	
	vec_brd[y][x] = arg_color;

	return;
}



void Board::show_cmd(void){
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			if(vec_brd[i][j] == white) std::cout << "  ";
			else std::cout << "O ";
		}
		std::cout << std::endl;
	}

	return;
}
