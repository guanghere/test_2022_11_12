#pragma once

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 5
#define COL 5

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void Player_move(char board[ROW][COL], int row, int col);

//电脑下棋
void Computer_move(char board[ROW][COL], int row, int col);

//判断输赢
char who_win(char board[ROW][COL], int row, int col);