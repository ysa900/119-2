#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include<mmsystem.h>
#define ENTER 13
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define KEY_LEFT 0x41
#define KEY_RIGHT 0x44
#define MAX 40
#define BACKCOLOR 0


void game1();
void game2();
void game3();
void exitgame();
void instruction1();
void instruction2();
void instruction3();
void menu();
void title();
void gotoxy(int x, int y);
void map();
void SetTitle(char* _szConsoleName);
void Setcolor(unsigned char _BgColor, unsigned char _TextColor);
void Setcursor(BOOL _bShow);
void gameover();

int main(void)
{
	system("mode con cols=120 lines=40");


	title();


	return 0;
}
void title()
{
	int start;

	gotoxy(35, 8);
	printf("□□□□□□□□□□□□□□□□□□□□□□□□\n");
	gotoxy(35, 9);
	printf("□                                            □\n");
	gotoxy(35, 10);
	printf("□");
	printf(" 3주차 자유주제 프로젝트 ");
	printf(" - 부제:종합 게임");
	printf(" ");
	printf(" □\n");
	gotoxy(35, 11);
	printf("□                                            □\n");
	gotoxy(35, 12);
	printf("□                                            □\n");
	gotoxy(35, 13);
	printf("□□□□□□□□□□□□□□□□□□□□□□□□\n");

	gotoxy(35, 14);
	printf("시작하려면 1를 입력하세요(문자입력x):");
	scanf("%d", &start);



	switch (start)
	{
	case 1:
		system("cls");
		menu();
		break;
	default:
		gotoxy(35, 15);
		printf("잘못 입력하셨습니다.\n");
		Sleep(1000);
		system("cls");
		title();
		break;
	}



}
void menu()
{
	int choice;
	
	system("mode con cols=120 lines=40");
	map();


	gotoxy(50, 8);
	printf("1.숫자야구게임\n");
	gotoxy(50, 9);
	printf("2.별 피하기게임");
	gotoxy(50, 10);
	printf("3.LOW & HIGH 게임\n");
	gotoxy(50, 11);
	printf("4.게임 끝내기");

	printf("\n");
	printf("\n");
	gotoxy(50, 14);
	printf("선택:");
	scanf("%d", &choice);

	system("cls");

	if (choice == 1)
	{
		game1();
	}
	else if (choice == 2)
	{
		game2();


	}
	else if (choice == 3)
	{
		game3();

	}
	else if (choice == 4)
	{
		exitgame();


	}
	else
	{
		gotoxy(35, 15);
		printf("잘못 입력하셨습니다.\n");
		Sleep(1000);
		system("cls");
		menu();

	}

}
void game1()
{
	int key;
	int com[3];
	int i, j;
	int temp;
	int user[3];
	int count = 1;
	int strike;
	int ball;

	instruction1();

	map();


	srand(time(NULL));
	for (i = 0; i < 3; i++)
	{
		temp = (rand() % 9) + 1;
		com[i] = temp;
		for (j = 0; j < i; j++)
			if (temp == com[j] && i != j)
				i--;
	}

	while (1)
	{
		gotoxy(38, 7);
		printf("%d회차 숫자야구\n", count);

		while (1)
		{
			gotoxy(38, 8);
			printf("1부터 9까지 숫자 3개를 입력하세요:");
			scanf("%d %d %d", &user[0], &user[1], &user[2]);
			if (user[0] < 1 || user[0]>9 || user[1] < 1 || user[1]>9 || user[2] < 1 || user[2]>9)
			{
				gotoxy(38, 8);
				printf("범위 외의 숫자를 입력하셨습니다. 다시 입력하세요.");
				Sleep(2000);
				system("cls");
				gotoxy(38, 7);
				printf("%d회차 숫자야구\n", count);
				map();
				continue;

			}
			else if (user[0] == user[1] || user[0] == user[2] || user[1] == user[2])
			{
				gotoxy(38, 8);
				printf("중복된 숫자를 입력하셨습니다. 다시 입력하세요.");
				Sleep(2000);
				system("cls");
				gotoxy(38, 7);
				printf("%d회차 숫자야구\n", count);
				map();
				continue;

			}

			break;

		}

		ball = 0;
		strike = 0;

		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (com[i] == user[j])
					if (i == j)
						strike++;
					else
						ball++;
		gotoxy(38, 9);
		printf("[결과]스트라이크:%d, 볼:%d", strike, ball);
		Sleep(2000);
		system("cls");
		gotoxy(38, 7);
		printf("%d회차 숫자야구\n", count);
		map();

		if (strike == 3)
		{
			gotoxy(38, 10);
			printf("승리했습니다.");
			break;


		}
		else if (count == 9)
		{
			gotoxy(38, 10);
			printf("패배했습니다.  정답: %d,%d,%d", com[0], com[1], com[2]);
			break;
		}
		count++;
	}
	Sleep(1000);
	system("cls");

	menu();


}
void game2()
{
	
	instruction2();


	struct STAR {

		int x = 0;
		int y = 0;
		bool Active = false;


	};
	struct OBJECT{
	
		int x = 19;
		int y = 28;
		bool active = true;

	};


	STAR star[MAX];
	OBJECT player;

	int score = 0;
	int bx = 0, by = 0;
	bool bullet = false;




	srand(time(NULL));

	system("mode con cols=40 lines=30");

	while (1)
	{

		Setcursor(0);
		system("cls");

		for (int i = 0; i < MAX; i++)
		{
			if (!star[i].Active)
			{
				star[i].x = (rand() % 20) * 2;
				star[i].y = 0;
				star[i].Active = true;

				break;
			}
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			player.x -= 1;
			if (player.x < 0)player.x = 0;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			player.x += 1;
			if (player.x > 38)player.x = 38;
		}
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (!bullet)
			{
				bx = player.x;
				by = player.y - 1;
				bullet = true;
			}
		}
		if (bullet)
		{
			gotoxy(bx, by);
			printf("↑");
			by--;
			if (by < 0)bullet = false;
		}

		for (int i = 0; i < MAX; i++)
		{
	
			
			if (star[i].Active)
			{
				Setcolor(BACKCOLOR,14);
				gotoxy(star[i].x, star[i].y);
				printf("☆");
				star[i].y++;

				if (star[i].y == player.y)
				{
					if (star[i].x == player.x)
						player.active = false;

				}

				if (star[i].y > player.y )star[i].Active = false;
				
				
			}
		}

		
		if (player.active)
		{
			score++;
			gotoxy(player.x, player.y);
			printf("▲");
			gotoxy(0, 0);
			printf("Score:%d", score);
		}
		else
		{
			gotoxy(player.x, player.y);
			printf("▦");
			system("cls");
			gotoxy(13, 5);
			printf("충돌하셨습니다.");
			gotoxy(13, 7);
			printf("Score:%d",score);
			Sleep(2000);
			
		
			break;

		}

		Sleep(50);
	}	
	Setcolor(BACKCOLOR, 15);
	system("cls");
	menu();
		
}
void game3()
{
	int key;
	int com;
	int player;
	int count = 0;

	instruction3();

	map();



	srand(time(NULL));

	com = rand() % 100 + 1;

	while (1)
	{
		gotoxy(38, 7);
		printf("숫자를 입력하세요:");
		scanf("%d", &player);
		system("cls");

		map();
		count++;
		gotoxy(38, 8);
		if (player < com)
		{
			printf("HIGH\n");

		}
		else if (player > com)
		{
			printf("LOW\n");

		}
		else if (player == com)
		{
			printf(" 정답입니다..\n");
			gotoxy(38, 9);
			printf(" %d번만에 맞추셨습니다..\n", count);

			break;

		}


	}
	Sleep(1000);
	system("cls");

	menu();


}







void exitgame()
{
	gotoxy(50, 8);
	printf("게임을 종료합니다.");


}
void instruction1()
{
	map();

	
	
	gotoxy(34, 7);
	printf("--게임 설명--");
	Sleep(1000);
	gotoxy(34, 8);
	printf("1~9 까지의 숫자 3개를 맞추는 게임 입니다.");
	Sleep(1000);
	gotoxy(34, 10);
	printf("숫자만 맞추면 볼,숫자와 자리까지 맞추면 스트라이크 입니다.");
	Sleep(1000);
	gotoxy(34, 12);
	printf("9회까지 맞추지 못하면 패배하게 됩니다.");
	Sleep(1000);
	gotoxy(34, 14);
	printf("게임을 시작합니다.");
	Sleep(3000);
	system("cls");

}
void instruction2()
{
	map();



	gotoxy(34, 7);
	printf("--게임 설명--");
	Sleep(1000);
	gotoxy(34, 8);
	printf("무수히 떨어지는 별을 피하는 게임입니다.");
	Sleep(1000);
	gotoxy(34, 10);
	printf("피하는 시간에 따라 스코어가 올라갑니다.");
	Sleep(1000);
	gotoxy(34, 12);
	printf("별과 부딧히게 되면 게임이 종료됩니다.");
	Sleep(1000);
	gotoxy(34, 14);
	printf("조작:→,←,");
	Sleep(3000);
	system("cls");

}
void instruction3()
{

	map();



	gotoxy(34, 7);
	printf("--게임 설명--");
	Sleep(1000);
	gotoxy(34, 8);
	printf("1~100 까지 무작위 수가 주어집니다.");
	Sleep(1000);
	gotoxy(34, 10);
	printf("무작위 수가 플레이어가 제시한 수보다 작으면  LOW");
	Sleep(1000);
	gotoxy(34, 12);
	printf("무작위 수가 크면 HIGH 입니다.");
	Sleep(1000);
	gotoxy(34, 14);
	printf("숫자를 맞추게 되면 게임이 종료됩니다.");
	Sleep(3000);
	system("cls");

}

void gotoxy(int x, int y)
{

	COORD pos{ x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void map()
{
	int i;
	int x = 1;
	int y = 3;

	gotoxy(32, 4);
	for (i = 0; i < 30; i++)
	{

		printf("□");
	}


	for (i = y + 1; i < y + 20 - 1; i++)
	{
		gotoxy(32, i);
		printf("□");

	}
	for (i = 5; i < 23; i++)
	{
		gotoxy(90, i);
		printf("□");


	}
	gotoxy(32, 22);
	for (i = 0; i < 30; i++)
	{

		printf("□");

	}
}
void SetTitle(char* _szConsoleName)
{
	SetConsoleTitle(_szConsoleName);

}
void Setcolor(unsigned char _BgColor, unsigned char _TextColor)
{
	if (_BgColor > 15 || _TextColor > 15)return;

	unsigned short ColorNum = (_BgColor << 4) | _TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}
void Setcursor(BOOL _bShow)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = _bShow;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

