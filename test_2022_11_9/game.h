#pragma once

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 5
#define COL 5

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void Player_move(char board[ROW][COL], int row, int col);

//��������
void Computer_move(char board[ROW][COL], int row, int col);

//�ж���Ӯ
char who_win(char board[ROW][COL], int row, int col);