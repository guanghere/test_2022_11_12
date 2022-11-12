#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"


void menu()
{
	printf("********************\n");
	printf("*******1.play*******\n");
	printf("*******0.over*******\n");
	printf("********************\n");
}

void game()
{

	char ret = 0;

	//存放下棋的数据
	char board[ROW][COL] = { 0 };

	//初始化棋盘为全空格
	InitBoard(board, ROW, COL);

	//打印棋盘
	DisplayBoard(board, ROW, COL);

	while (1)
	{
		//玩家下棋
		Player_move(board, ROW, COL);

		DisplayBoard(board, ROW, COL);

		ret = who_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		//电脑下棋
		Computer_move(board, ROW, COL);

		DisplayBoard(board, ROW, COL);

		ret = who_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}

//	who_win的作用

//	玩家赢返回-'*'
//	电脑赢返回-'#'
//	平局	返回---'Q'
//	继续	返回---'C'

	if (ret == '*')
	{
		printf("\n菜鸡,你赢了!\n");
	}
	else if (ret == '#')
	{
		printf("\n菜鸡,居然能让电脑赢!\n");
	}
	else
	{
		printf("\n菜鸡,居然和电脑打平了!\n");
	}
}





void test()
{
	int input = 0;
	srand((unsigned)time(NULL));

	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("输入错误，请重新输入");
			break;
		}
	} while (input);
}


int main()
{
	test();

	return 0;
}