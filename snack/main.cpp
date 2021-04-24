#include "snake.h"


int main() {

	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cci);

	srand(time(NULL));//播种随机数种子

	initWall();
	initSnake();

	initFood();

	initUI_console();
	//initUI_easyX();

	playGame();
	showScore();
	system("pause");
	return 0;
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

//初始化界面
void initUI_console() {

	

	COORD pos = { 0 };

	for (size_t i = 0; i < snake.size; i++)
	{
		pos.X = snake.body[i].X;
		pos.Y = snake.body[i].Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		if (i == 0) {
			putchar('@');
		}
		else
		{
			putchar('*');
		}

	}

	
	// 去除蛇尾
	pos.X = lastX;
	pos.Y = lastY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	putchar(' ');
	


	//画食物
	pos.X = food.X;
	pos.Y = food.Y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	putchar('#');



}


void playGame() {


	char key = 'd';


	//判断蛇撞墙
	while (snake.body[0].X >=0 && snake.body[0].X < WIDTH
		&& snake.body[0].Y >=0 && snake.body[0].Y < HEIGHT)
	{
		
		initUI_console();

		if (_kbhit()) {
			key = _getch();
		}

		switch (key)
		{
		case 'w': kx = 0; ky = -1; break;
		case 's': kx = 0; ky = +1; break;
		case 'd': kx = +1; ky = 0; break;
		case 'a': kx = -1; ky = 0; break;
		default:
			break;
		}



		//判断蛇撞身体
		for (size_t i = 1; i < snake.size; i++)
		{
			if (snake.body[0].X == snake.body[i].X
			&& snake.body[0].Y == snake.body[i].Y)
			{
				return;//蛇头撞身体
			}
		}
		//蛇头撞食物
		if (snake.body[0].X == food.X && snake.body[0].Y == food.Y)
		{
			initFood();
			snake.size++;
			score = score + 5;
			sleepSecond -= 10;	// 加速
		}

		// 存储蛇尾坐标
		lastX = snake.body[snake.size - 1].X;
		lastY = snake.body[snake.size - 1].Y;

		for ( size_t i = snake.size -1 ; i >0; i--)
		{
			snake.body[i].X = snake.body[i - 1].X;

			snake.body[i].Y = snake.body[i - 1].Y;
		}
		snake.body[0].X += kx;
		snake.body[0].Y += ky;

		Sleep(sleepSecond);

		//system("cls");

	}

}




void initWall(void)
{
	for (size_t i = 0; i <= HEIGHT; i++)	// 多行
	{
		for (size_t j = 0; j <= WIDTH; j++)			// 一行中的多列
		{
			if (j == WIDTH)
			{
				printf("|");
			}
			else if (i == HEIGHT)
			{
				printf("_");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}


void showScore() {

	COORD pos;
	pos.X = 0;
	pos.Y = HEIGHT + 2;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	printf("Game over!!\n");
	printf("score is %d\n",score);
}



void initUI_easyX() {

	initgraph(WIDTH,HEIGHT,NULL);	
	circle(200, 200, 100);	
	_getch();				
}


