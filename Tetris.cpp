
#include <iostream>
#include <vector>
#include <conio.h>
#include <time.h>

class Tetris
{
protected:

	std::vector<std::vector<int>> stage;
	std::vector<std::vector<int>> field;

	std::vector<std::vector<int>> block;
	std::vector<std::vector<std::vector<int>>> block_list;

	// координати
	int y = 0;
	int x = 4;
	bool gameover = false;
	size_t GAMESPEED = 20000;

public:

	Tetris()
	{
		stage = { 22, std::vector<int>(13, 0) };
		field = { 22, std::vector<int>(13, 0) };

		block = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
		};

		block_list =
		{
			{
				{ 0, 1, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 1, 0, 0 }
			},
			{
				{ 0, 0, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 1, 0, 0 }
			},
			{
				{ 0, 0, 1, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			{
				{ 0, 1, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 1, 1, 1, 0 },
				{ 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 0, 1, 0 }
			}
		};
	}

	int gameOver()
	{

		char a;
		std::cout << " #####     #    #     # ####### ####### #     # ####### ######\n";
		std::cout << "#     #   # #   ##   ## #       #     # #     # #       #     #\n";
		std::cout << "#        #   #  # # # # #       #     # #     # #       #     #\n";
		std::cout << "#  #### #     # #  #  # #####   #     # #     # #####   ######\n";
		std::cout << "#     # ####### #     # #       #     #  #   #  #       #   #\n";
		std::cout << "#     # #     # #     # #       #     #   # #   #       #    #\n";
		std::cout << " #####  #     # #     # ####### #######    #    ####### #     #\n";
		std::cout << "\n\nPress any key and enter\n";
		std::cin >> a;
		return 0;
	}

	bool makeBlocks()
	{
		srand(time(NULL));

		x = 4;
		y = 0;

		int blockType = rand() % 7;

		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				block[i][j] = 0;
				block[i][j] = block_list[blockType][i][j];
			}
		}

		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				field[i][j + 4] = stage[i][j + 4] + block[i][j];

				if (field[i][j + 4] > 1)
				{
					gameover = true;
					return true;
				}
			}
		}
		return false;
	}

	void display()
	{
		system("cls");

		for (size_t i = 0; i < 21; i++)
		{
			for (size_t j = 0; j < 12; j++)
			{
				switch (field[i][j])
				{
				case 0:
					std::cout << " "; //<< std::flush;
					break;
				case 9:
					std::cout << "@";//<< std::flush;
					break;
				default:
					std::cout << "#"; //<< std::flush;
					break;
				}
			}
			std::cout << std::endl;
		}

		std::cout << "\n\tA: left\tS: down\tD: right \t Rotation[Space]";

		if (gameover)
		{
			system("cls");
			gameOver();
		}
	}

	void initGame()
	{
		for (size_t i = 0; i <= 20; i++)
		{
			for (size_t j = 0; j <= 11; j++)
			{
				if ((j == 0) || (j == 11) || (i == 20))
				{
					field[i][j] = stage[i][j] = 9;
				}
				else
				{
					field[i][j] = stage[i][j] = 0;
				}
			}
		}

		makeBlocks();

		display();
	}


	void title()
	{
		system("cls");

		std::cout << "#==============================================================================#\n";

		std::cout << "####### ####### ####### ######    ###    #####\n";
		std::cout << "   #    #          #    #     #    #    #     #\n";
		std::cout << "   #    #          #    #     #    #    #\n";
		std::cout << "   #    #####      #    ######     #     #####\n";
		std::cout << "   #    #          #    #   #      #          #\n";
		std::cout << "   #    #          #    #    #     #    #     #\n";
		std::cout << "   #    #######    #    #     #   ###    #####\t\t";
		std::cout << "\n\n\n\n";

		std::cout << "\t<menu>\n";
		std::cout << "\t1: Start Game\n\t2: Quit\n\n";

		std::cout << "#==============================================================================#\n";
		std::cout << "Choose >> ";

	}


	int menu()
	{
		title();

		int select_num = 0;

		std::cin >> select_num;

		switch (select_num)
		{
		case 1:
		case 2:
		case 3:
			break;
		default:
			select_num = 0;
			break;
		}

		return select_num;
	}


	void moveBlock(int x2, int y2)
	{

		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				field[y + i][x + j] -= block[i][j];
			}
		}
		//оновлення координати
		x = x2;
		y = y2;

		// обновлення 
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				field[y + i][x + j] += block[i][j];
			}
		}

		display();
	}

	void collidable()
	{
		for (size_t i = 0; i < 21; i++)
		{
			for (size_t j = 0; j < 12; j++)
			{
				stage[i][j] = field[i][j];
			}
		}
	}

	bool isCollide(int x2, int y2)
	{
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				if (block[i][j] && stage[y2 + i][x2 + j] != 0)
				{
					return true;
				}
			}
		}
		return false;
	}



	bool rotateBolck()
	{
		std::vector<std::vector<int>> tmp(4, std::vector<int>(4, 0));

		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				tmp[i][j] = block[i][j];
			}
		}

		for (size_t i = 0; i < 4; i++)
		{ //ротація
			for (size_t j = 0; j < 4; j++)
			{
				block[i][j] = tmp[3 - j][i];
			}
		}

		if (isCollide(x, y))
		{ // зупинка ротації якщо виходить за межі поля
			for (size_t i = 0; i < 4; i++)
			{
				for (size_t j = 0; j < 4; j++)
				{
					block[i][j] = tmp[i][j];
				}
			}
			return true;
		}

		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				field[y + i][x + j] -= tmp[i][j];
				field[y + i][x + j] += block[i][j];
			}
		}

		display();

		return false;
	}

	void userInput()
	{
		char key;

		key = _getch();

		switch (key)
		{
		case 'd':
			if (!isCollide(x + 1, y))
			{
				moveBlock(x + 1, y);
			}
			break;
		case 'a':
			if (!isCollide(x - 1, y))
			{
				moveBlock(x - 1, y);
			}
			break;
		case 's':
			if (!isCollide(x, y + 1))
			{
				moveBlock(x, y + 1);
			}
			break;
		case ' ':
			rotateBolck();
		}
	}

	void spwanBlock()
	{
		if (!isCollide(x, y + 1))
		{
			moveBlock(x, y + 1);
		}
		else
		{
			collidable();
			makeBlocks();
			display();
		}
	}

	void destroyLine()
	{
		int k = 20 - 1;
		for (int i = 20 - 1; i > 0; i--)
		{
			int count = 0;
			for (int j = 0; j < 11; j++)
			{
				if (field[i][j]) count++;
				field[k][j] = field[i][j];
			}
			if (count < 11)
				k--;
		}
	}

	void gameLoop()
	{
		size_t time = 0;
		initGame();

		while (!gameover)
		{
			destroyLine();

			if (_kbhit())
			{
				userInput();
			}

			if (time < GAMESPEED)
			{
				time++;
			}
			else
			{
				spwanBlock();
				time = 0;
			}
		}

	}

	int Start()
	{
		switch (menu())
		{
		case 1:

			gameLoop();
			break;

		case 2:

			return 0;

		case 0:

			std::cerr << "Choose 1~2" << std::endl;
			return -1;
		}
		return 0;
	}

};

int main()
{
	Tetris t;

	t.Start();
}