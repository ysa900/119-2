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
	printf("�������������������������\n");
	gotoxy(35, 9);
	printf("��                                            ��\n");
	gotoxy(35, 10);
	printf("��");
	printf(" 3���� �������� ������Ʈ ");
	printf(" - ����:���� ����");
	printf(" ");
	printf(" ��\n");
	gotoxy(35, 11);
	printf("��                                            ��\n");
	gotoxy(35, 12);
	printf("��                                            ��\n");
	gotoxy(35, 13);
	printf("�������������������������\n");

	gotoxy(35, 14);
	printf("�����Ϸ��� 1�� �Է��ϼ���(�����Է�x):");
	scanf("%d", &start);



	switch (start)
	{
	case 1:
		system("cls");
		menu();
		break;
	default:
		gotoxy(35, 15);
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
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
	printf("1.���ھ߱�����\n");
	gotoxy(50, 9);
	printf("2.�� ���ϱ����");
	gotoxy(50, 10);
	printf("3.LOW & HIGH ����\n");
	gotoxy(50, 11);
	printf("4.���� ������");

	printf("\n");
	printf("\n");
	gotoxy(50, 14);
	printf("����:");
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
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
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
		printf("%dȸ�� ���ھ߱�\n", count);

		while (1)
		{
			gotoxy(38, 8);
			printf("1���� 9���� ���� 3���� �Է��ϼ���:");
			scanf("%d %d %d", &user[0], &user[1], &user[2]);
			if (user[0] < 1 || user[0]>9 || user[1] < 1 || user[1]>9 || user[2] < 1 || user[2]>9)
			{
				gotoxy(38, 8);
				printf("���� ���� ���ڸ� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���.");
				Sleep(2000);
				system("cls");
				gotoxy(38, 7);
				printf("%dȸ�� ���ھ߱�\n", count);
				map();
				continue;

			}
			else if (user[0] == user[1] || user[0] == user[2] || user[1] == user[2])
			{
				gotoxy(38, 8);
				printf("�ߺ��� ���ڸ� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���.");
				Sleep(2000);
				system("cls");
				gotoxy(38, 7);
				printf("%dȸ�� ���ھ߱�\n", count);
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
		printf("[���]��Ʈ����ũ:%d, ��:%d", strike, ball);
		Sleep(2000);
		system("cls");
		gotoxy(38, 7);
		printf("%dȸ�� ���ھ߱�\n", count);
		map();

		if (strike == 3)
		{
			gotoxy(38, 10);
			printf("�¸��߽��ϴ�.");
			break;


		}
		else if (count == 9)
		{
			gotoxy(38, 10);
			printf("�й��߽��ϴ�.  ����: %d,%d,%d", com[0], com[1], com[2]);
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
			printf("��");
			by--;
			if (by < 0)bullet = false;
		}

		for (int i = 0; i < MAX; i++)
		{
	
			
			if (star[i].Active)
			{
				Setcolor(BACKCOLOR,14);
				gotoxy(star[i].x, star[i].y);
				printf("��");
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
			printf("��");
			gotoxy(0, 0);
			printf("Score:%d", score);
		}
		else
		{
			gotoxy(player.x, player.y);
			printf("��");
			system("cls");
			gotoxy(13, 5);
			printf("�浹�ϼ̽��ϴ�.");
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
		printf("���ڸ� �Է��ϼ���:");
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
			printf(" �����Դϴ�..\n");
			gotoxy(38, 9);
			printf(" %d������ ���߼̽��ϴ�..\n", count);

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
	printf("������ �����մϴ�.");


}
void instruction1()
{
	map();

	
	
	gotoxy(34, 7);
	printf("--���� ����--");
	Sleep(1000);
	gotoxy(34, 8);
	printf("1~9 ������ ���� 3���� ���ߴ� ���� �Դϴ�.");
	Sleep(1000);
	gotoxy(34, 10);
	printf("���ڸ� ���߸� ��,���ڿ� �ڸ����� ���߸� ��Ʈ����ũ �Դϴ�.");
	Sleep(1000);
	gotoxy(34, 12);
	printf("9ȸ���� ������ ���ϸ� �й��ϰ� �˴ϴ�.");
	Sleep(1000);
	gotoxy(34, 14);
	printf("������ �����մϴ�.");
	Sleep(3000);
	system("cls");

}
void instruction2()
{
	map();



	gotoxy(34, 7);
	printf("--���� ����--");
	Sleep(1000);
	gotoxy(34, 8);
	printf("������ �������� ���� ���ϴ� �����Դϴ�.");
	Sleep(1000);
	gotoxy(34, 10);
	printf("���ϴ� �ð��� ���� ���ھ �ö󰩴ϴ�.");
	Sleep(1000);
	gotoxy(34, 12);
	printf("���� �ε����� �Ǹ� ������ ����˴ϴ�.");
	Sleep(1000);
	gotoxy(34, 14);
	printf("����:��,��,");
	Sleep(3000);
	system("cls");

}
void instruction3()
{

	map();



	gotoxy(34, 7);
	printf("--���� ����--");
	Sleep(1000);
	gotoxy(34, 8);
	printf("1~100 ���� ������ ���� �־����ϴ�.");
	Sleep(1000);
	gotoxy(34, 10);
	printf("������ ���� �÷��̾ ������ ������ ������  LOW");
	Sleep(1000);
	gotoxy(34, 12);
	printf("������ ���� ũ�� HIGH �Դϴ�.");
	Sleep(1000);
	gotoxy(34, 14);
	printf("���ڸ� ���߰� �Ǹ� ������ ����˴ϴ�.");
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

		printf("��");
	}


	for (i = y + 1; i < y + 20 - 1; i++)
	{
		gotoxy(32, i);
		printf("��");

	}
	for (i = 5; i < 23; i++)
	{
		gotoxy(90, i);
		printf("��");


	}
	gotoxy(32, 22);
	for (i = 0; i < 30; i++)
	{

		printf("��");

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

