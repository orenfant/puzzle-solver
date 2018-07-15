#include <vector>
#include <string>

enum Color {
	white,
	black,
};

class Board {
private:
	int height = 0;
	int width = 0;

	std::vector<std::vector<Color>> vec_brd;
public:
	Board(int arg_height, int arg_width);
	void resize(int arg_height, int arg_width);

	int load_file(std::string filename);

	void assign_cell(int y, int x, Color arg_color);
	
	void show_cmd(void);
};

