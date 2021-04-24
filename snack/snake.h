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

//定义蛇身体对象
struct BODY
{
	int X;
	int Y;
};

//定义蛇对象
struct snake
{
	struct BODY body[WIDTH * HEIGHT];
	int size;
} snake;

//定义食物对象 
struct FOOD
{
	int X;
	int Y;
} food;


int score = 0;



//声明函数
void initSnake();

void initFood();

#endif // !__SNAKE_H__
