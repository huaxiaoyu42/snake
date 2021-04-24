#include "snake.h"






int main() {


	srand(time(NULL));//播种随机数种子

	initSnake();

	initFood();

	
	printf("snake:x=%d,y=%d\n",snake.body[0].X,snake.body[0].Y);
	printf("food:x=%d,y=%d\n", food.X, food.Y);

	system("pause");
	return EXIT_SUCCESS;
}


void initSnake() {
	snake.size = 2;

	//初始化蛇头
	snake.body[0].X = WIDTH / 2;
	snake.body[0].Y = HEIGHT / 2;

	//初始化一节蛇的身体
	snake.body[1].X = WIDTH / 2 - 1;
	snake.body[1].Y = HEIGHT / 2;
}


void initFood() {
	//初始化食物的坐标
	food.X = rand() % WIDTH;
	food.Y = rand() % HEIGHT;
}

void initUI() {

}
