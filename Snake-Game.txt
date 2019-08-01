#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include<ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int length;
int bend_no;
int len;
char key;
void loading();
int life;
void Delay();
void Move();
void Food();
void Score();
void Instructions();
void Console_change(int x, int y);
void Bend();
void Edges();
void Down();
void Left();
void Up();
void Right();
void ExitGame();
void Speedlevel();
long double speed;

struct coordinate{
    int x;
    int y;
    int direction;
};

typedef struct coordinate coordinate;

coordinate  head, bend[500],food,body[50];

int main()
{

    Instructions();

    system("cls");

    loading();
    getch();

    system("cls");

    Speedlevel();

    system("cls");
    length=5;

    head.x=25;

    head.y=20;

    head.direction=RIGHT;

    Edges();

    Food(); //Randomly generating the food

    life=2; //number of extra lives

    bend[0]=head;

    Move();   //initialing initial bend coordinate

    return 0;
}
void Speedlevel()
{
    int s;
    long double speedup;
   printf("Enter the speed level of the snake (1, 2, 3) ");
   scanf("%d",&s);
   if(s==1)
      speed=10000000;  //To set the speed level of the snake
   else if(s==2)
      speed=1000000;
   else
      speed=100000;

}

void Move()
{
    int a,i;

    do{

        Food();
        len=0;

        for(i=0;i<30;i++)
        {

            body[i].x=0;

            body[i].y=0;

            if(i==length)
            break;
        }

        Delay();
        Edges();

        if(head.direction==RIGHT)

            Right();

        else if(head.direction==LEFT)

            Left();

        else if(head.direction==DOWN)

            Down();

        else if(head.direction==UP)

            Up();

        ExitGame();

    }while(!kbhit());

    a=getch();

    if(a==27)

    {

        system("cls");

        exit(0);

    }
    key=getch();

    if((key==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(key==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(key==UP&&head.direction!=DOWN&&head.direction!=UP)||(key==DOWN&&head.direction!=UP&&head.direction!=DOWN))

    {

        bend_no++;

        bend[bend_no]=head;

        head.direction=key;

        if(key==UP)
            head.y--;
        if(key==DOWN)
            head.y++;
        if(key==RIGHT)
            head.x++;
        if(key==LEFT)
            head.x--;
        Move();
    }
    else if(key==27)
    {
        system("cls");
        exit(0);
    }

    else
    {
        printf("\a");
        Move();
    }
}


void Right()
{
    int i;
    for(i=0;i<=(head.x-bend[bend_no].x)&&len<length;i++)
    {
        //Console_change((head.x-i),head.y);
        body[len].x=head.x-i;
        body[len].y=head.y;
        Console_change(body[len].x,body[len].y);
        {
            if(len==0)
                printf(">");
            else
                printf("*");
        }
        /*body[len].x=head.x-i;
        body[len].y=head.y;*/
        len++;
    }
    Bend();
    if(!kbhit())
        head.x++;
}


void Left()
{
    int i;
    for(i=0;i<=(bend[bend_no].x-head.x)&&len<length;i++)
    {
        Console_change((head.x+i),head.y);
       {
                if(len==0)
                    printf("<");
                else
                    printf("*");
        }
        body[len].x=head.x+i;
        body[len].y=head.y;
        len++;
    }
    Bend();
    if(!kbhit())
        head.x--;

}


void Bend()
{
    int i,j,diff;
    for(i=bend_no;i>=0&&len<length;i--)
    {
            if(bend[i].x==bend[i-1].x)
            {
                diff=bend[i].y-bend[i-1].y;
                if(diff<0)
                    for(j=1;j<=(-diff);j++)
                    {
                        body[len].x=bend[i].x;
                        body[len].y=bend[i].y+j;
                        Console_change(body[len].x,body[len].y);
                        printf("*");
                        len++;
                        if(len==length)
                            break;
                    }
                else if(diff>0)
                    for(j=1;j<=diff;j++)
                    {
                        /*Console_change(bend[i].x,(bend[i].y-j));
                        printf("*");*/
                        body[len].x=bend[i].x;
                        body[len].y=bend[i].y-j;
                        Console_change(body[len].x,body[len].y);
                        printf("*");
                        len++;
                        if(len==length)
                            break;
                    }
            }
        else if(bend[i].y==bend[i-1].y)
        {
            diff=bend[i].x-bend[i-1].x;
            if(diff<0)
                for(j=1;j<=(-diff)&&len<length;j++)
                {
                    /*Console_change((bend[i].x+j),bend[i].y);
                    printf("*");*/
                    body[len].x=bend[i].x+j;
                    body[len].y=bend[i].y;
                    Console_change(body[len].x,body[len].y);
                        printf("*");
                   len++;
                   if(len==length)
                           break;
               }
           else if(diff>0)
               for(j=1;j<=diff&&len<length;j++)
               {
                   /*Console_change((bend[i].x-j),bend[i].y);
                   printf("*");*/
                   body[len].x=bend[i].x-j;
                   body[len].y=bend[i].y;
                   Console_change(body[len].x,body[len].y);
                       printf("*");
                   len++;
                   if(len==length)
                       break;
               }
       }
   }
}

void Up()
{
   int i;
   for(i=0;i<=(bend[bend_no].y-head.y)&&len<length;i++)
   {
       Console_change(head.x,head.y+i);
       {
           if(len==0)
               printf("^");
           else
               printf("*");
       }
       body[len].x=head.x;
       body[len].y=head.y+i;
       len++;
   }
   Bend();
   if(!kbhit())
       head.y--;
}


void Down()
{
    int i;
    for(i=0;i<=(head.y-bend[bend_no].y)&&len<length;i++)
    {
    Console_change(head.x,head.y-i);
        {
            if(len==0)
                printf("v");
            else
                printf("*");
        }
        body[len].x=head.x;
        body[len].y=head.y-i;
        len++;
    }
    Bend();
    if(!kbhit())
        head.y++;
}

void ExitGame()
{
    int i,check=0;
    for(i=4;i<length;i++)   //starts with 4 because it needs minimum 4 element to touch its own body
    {
        if(body[0].x==body[i].x&&body[0].y==body[i].y)
        {
            check++;    //check value increases as the coordinates of head is equal to any other body coordinate
        }
        if(i==length||check!=0)
            break;
    }
    if(head.x<=10||head.x>=70||head.y<=10||head.y>=30||check!=0)
    {
        life--;
        if(life>=0)
        {
            head.x=25;
            head.y=20;
            bend_no=0;
            head.direction=RIGHT;
            Move();
        }
        else
        {
            system("cls");
            printf("All lives completed\nBetter Luck Next Time!!!\nPress any key to quit the game\n");
            getch();
            exit(0);
        }
    }
}

void Delay()
{
    long double i;
    Score();
    for(i=0;i<=speed;i++);
}

void Food()
{
   if(head.x==food.x&&head.y==food.y)
    {
        length++;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
            food.y+=11;
    }
    else if(food.x==0)/*to create food for the first time coz global variable are initialized with 0*/
    {
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
            food.y+=11;
    }
}

void Edges()
{
   system("cls");
   int i;
   Console_change(food.x,food.y);
   printf("*");
   for(i=10;i<71;i++){
      Console_change(i,10);
      printf("-");
      Console_change(i,30);
      printf("_");
   }
   for(int i=10;i<31;i++){
      Console_change(10,i);
      printf("|");
      Console_change(70,i);
      printf("|");
   }
}

void loading()
{
    int i,j;
    system("cls");
    Console_change(20,10);
    printf("Loading.....");
    Console_change(15,11);
    for(i=0;i<=20;i++){
       for(j=0;j<=100000000;j++);
       printf("%c",177);
    }
    printf("\t\n\n\tPress any key to start..\n");
}

void Instructions()
{
    Console_change(13,10);
  printf("Welcome to SNAKE game(Press any key to continue)\n\n");
  getch();
  system("cls");
  printf("\tRules are:\n\n");
  printf("1.Use arrow keys to move the snake\n");
  printf("\n2.We provide the food in different places,You must be eat the food.\n");
  printf("  After ate the food the length of the snake will be increase every time\n");
  printf("\n3.If you hit the edges of the box or hit your own body you will be dead\n");
  printf("\n4.You have two lives, After completing the lives snake will be dead \n\n");
  printf("\t Press any key to play the game\n");
  getch();
    //if(getch()==27)
    // exit(0);
}

void Score()
{
   int score;
   Console_change(20,8);
   score=length-5;
   printf("SCORE : %d",(length-5));
   score=length-5;
   Console_change(50,8);
   printf("Life : %d",life);
   return score;
}

Console_change(int x,int y)
{
     COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
