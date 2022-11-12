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

	//������������
	char board[ROW][COL] = { 0 };

	//��ʼ������Ϊȫ�ո�
	InitBoard(board, ROW, COL);

	//��ӡ����
	DisplayBoard(board, ROW, COL);

	while (1)
	{
		//�������
		Player_move(board, ROW, COL);

		DisplayBoard(board, ROW, COL);

		ret = who_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		//��������
		Computer_move(board, ROW, COL);

		DisplayBoard(board, ROW, COL);

		ret = who_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}

//	who_win������

//	���Ӯ����-'*'
//	����Ӯ����-'#'
//	ƽ��	����---'Q'
//	����	����---'C'

	if (ret == '*')
	{
		printf("\n�˼�,��Ӯ��!\n");
	}
	else if (ret == '#')
	{
		printf("\n�˼�,��Ȼ���õ���Ӯ!\n");
	}
	else
	{
		printf("\n�˼�,��Ȼ�͵��Դ�ƽ��!\n");
	}
}





void test()
{
	int input = 0;
	srand((unsigned)time(NULL));

	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("�����������������");
			break;
		}
	} while (input);
}


int main()
{
	test();

	return 0;
}