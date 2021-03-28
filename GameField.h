#pragma once
#include "Stack.h"
#include <string>

class GameField
{
private:
	Stack field;
	int free_squares = 9;
public:
	GameField();
  GameField(std::string str_field); 
	int set_tic(int x, int y);
	int set_tac(int x, int y);
	void show_line(int line_num);
	void show();
	int check();
	int get_free_squares() const { return free_squares; };
	bool is_free(int x, int y);
  std::string to_string();
};
