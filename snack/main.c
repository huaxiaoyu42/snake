#include "snake.h"






int main() {


	srand(time(NULL));//�������������

	initSnake();

	initFood();

	
	printf("snake:x=%d,y=%d\n",snake.body[0].X,snake.body[0].Y);
	printf("food:x=%d,y=%d\n", food.X, food.Y);

	system("pause");
	return EXIT_SUCCESS;
}


void initSnake() {
	snake.size = 2;

	//��ʼ����ͷ
	snake.body[0].X = WIDTH / 2;
	snake.body[0].Y = HEIGHT / 2;

	//��ʼ��һ���ߵ�����
	snake.body[1].X = WIDTH / 2 - 1;
	snake.body[1].Y = HEIGHT / 2;
}


void initFood() {
	//��ʼ��ʳ�������
	food.X = rand() % WIDTH;
	food.Y = rand() % HEIGHT;
}

void initUI() {

}
