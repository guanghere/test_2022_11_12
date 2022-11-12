#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}


//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{

		//打印数据
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col-1)
			{
				printf("|");
			}
		}
		printf("\n");


		//打印分割的行
		if (i < row-1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");

		}
	}
}



//玩家下棋
void Player_move(char board[ROW][COL], int row, int col)
{
	printf("玩家下棋\n输入坐标开始下棋\n:>");
	int x = 0, y = 0;
	scanf("%d %d", &x, &y);
	while (1)
	{
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] ==' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}

			else
			{
			printf("该坐标被占用,已丢失一枚棋子\n");
			break;
			}

		}

		else
		{
			printf("坐标输入错误,已丢失一枚棋子\n");
			break;
		}

	}
}



//电脑下棋
void Computer_move(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("电脑下棋：>\n");

	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}

}

static int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;	//没满
			}
		}
	}
	return 1;	//	满了
}


//判断输赢
char who_win(char board[ROW][COL], int row, int col)
{
	//判断行
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][2] == board[i][3]) && (board[i][3] == board[i][4]) && (board[i][2] != ' '))
		{
			return board[i][3];
		}

	}

	//判断列
	for (i = 0; i < col; i++)
	{
		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[2][i] == board[3][i]) && (board[3][i] == board[4][i]) && (board[2][i] != ' '))
		{
			return board[2][i];
		}

	}

	//判断对角线

	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[2][2] == board[3][3]) && (board[3][3] == board[4][4]) && (board[2][2] != ' '))
	{
		return board[2][2];
	}

	if ((board[0][4] == board[1][3]) && (board[1][3] == board[2][2]) && (board[2][2] == board[3][1]) && (board[3][1] == board[4][0]) && (board[3][1] != ' '))
	{
		return board[3][1];
	}

	//判断平局
	if (is_full(board, row, col) == 1)
	{
		//printf("菜鸡,居然能平局\n");
		return 'Q';
	}

	//继续
	return 'C';
}