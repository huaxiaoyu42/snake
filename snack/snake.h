#ifndef __SNAKE_H__
#define __SNAKE_H__

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>


#define WIDTH 60
#define HEIGHT 20

//�������������
struct BODY
{
	int X;
	int Y;
};

//�����߶���
struct snake
{
	struct BODY body[WIDTH * HEIGHT];
	int size;
} snake;

//����ʳ����� 
struct FOOD
{
	int X;
	int Y;
} food;


int score = 0;



//��������
void initSnake();

void initFood();

#endif // !__SNAKE_H__
