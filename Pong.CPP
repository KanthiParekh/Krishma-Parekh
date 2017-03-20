/*
-----------------------RULES OF THE GAME -----------------------------
For Player1 - Keys are 'w'OR'W' and 's'OR'S' for 'up'& 'down' respectively.
For Player2 - Keys are '-' and '+' for 'up'& 'down' respectively.
For exit from the game- Keys are 'R' or 'r'.
Maximum Score - 4 to win.
*/

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>

void main()
{

    int paddle1_pos, paddle2_pos;
    float paddle1_vel, paddle2_vel;
    int PAD_HEIGHT, PAD_WIDTH, BALL_RADIUS,HALF_PAD_HEIGHT, HALF_PAD_WIDTH;
    int gd=DETECT,gm;

    initgraph(&gd,&gm,"C:\\TC\\BGI");

    int WIDTH,HEIGHT;

WIDTH = getmaxx();
HEIGHT = getmaxy();
BALL_RADIUS = 15;
PAD_WIDTH = 12;
PAD_HEIGHT = 80;
//HALF_PAD_WIDTH = PAD_WIDTH / 2;
HALF_PAD_HEIGHT = PAD_HEIGHT / 2;

int score1=0;
int score2=0;
//int flag=1;

//paddle position
paddle1_pos = HEIGHT/2;
paddle2_pos = HEIGHT/2;

//paddle velocity
 paddle1_vel = 0;
 paddle2_vel = 0;

//initialize ball_pos and ball_vel for new bal in middle of table
int ball_pos[2] = {WIDTH/2 , HEIGHT/2};
int ball_vel[2] = {4,4};
//int flag=0;
int cpad=1;
int s2=0;
int s1=0;
char str[25];
char str1[25];
itoa(score1,str,10);
itoa(score2,str1,10);

int max_score=4;

line(WIDTH/2,0,WIDTH/2,HEIGHT);
line(PAD_WIDTH,0,PAD_WIDTH,HEIGHT);
line(WIDTH-PAD_WIDTH,0,WIDTH-PAD_WIDTH,HEIGHT);


while(cpad){



//update ball

    ball_pos[0] += ball_vel[0];
    ball_pos[1] += ball_vel[1];

    //ball with upper and lower wall collisions
    if (ball_pos[1] <= BALL_RADIUS)
{
	ball_vel[0] = ball_vel[0];
	ball_vel[1] = -ball_vel[1];
}
    if (ball_pos[1] >= (HEIGHT-1)-BALL_RADIUS)
{
	ball_vel[0] = ball_vel[0];
	ball_vel[1] = -ball_vel[1];
}
    //spawn ball left or right
    if (ball_pos[0] < BALL_RADIUS+PAD_WIDTH)
{
       ball_pos[0]=WIDTH/2;
       ball_pos[1]=HEIGHT/2;
       ball_vel[0] *= -1;

}
    if (ball_pos[0] > WIDTH-PAD_WIDTH-BALL_RADIUS)
{

	ball_pos[0] = WIDTH/2;
	ball_pos[1] = HEIGHT/2;
	ball_vel[0] *= -1;
}
    setcolor(YELLOW);
    setfillstyle(1,YELLOW);
    //draw ball
    circle(ball_pos[0],ball_pos[1], BALL_RADIUS);
    floodfill(ball_pos[0],ball_pos[1],YELLOW);




    //keep paddle on the screen
    if (paddle1_pos-HALF_PAD_HEIGHT <= 0 && paddle1_vel < 0){

	paddle1_vel = 0;
}
    if (paddle2_pos-HALF_PAD_HEIGHT <= 0 && paddle2_vel < 0){

	paddle2_vel = 0;
}
    if (paddle1_pos+HALF_PAD_HEIGHT >= HEIGHT && paddle1_vel > 0){

       paddle1_vel = 0;
}
    if (paddle2_pos+HALF_PAD_HEIGHT >= HEIGHT && paddle2_vel > 0){

	paddle2_vel = 0;
}
    //update paddle's vertical position
    paddle1_pos += paddle1_vel;
    paddle2_pos += paddle2_vel;

    int points[]={0,paddle1_pos-HALF_PAD_HEIGHT, PAD_WIDTH,paddle1_pos-HALF_PAD_HEIGHT, PAD_WIDTH,paddle1_pos+HALF_PAD_HEIGHT, 0,paddle1_pos+HALF_PAD_HEIGHT,0, paddle1_pos-HALF_PAD_HEIGHT};
    int points1[]={WIDTH,paddle2_pos-HALF_PAD_HEIGHT,WIDTH-PAD_WIDTH,paddle2_pos-HALF_PAD_HEIGHT,WIDTH-PAD_WIDTH,paddle2_pos+HALF_PAD_HEIGHT,WIDTH,paddle2_pos+HALF_PAD_HEIGHT,WIDTH,paddle2_pos-HALF_PAD_HEIGHT};

    // draw paddles
    setcolor(WHITE);
    setfillstyle(1,RED);
    drawpoly(5,points);
    drawpoly(5,points1);
    fillpoly(5,points);
    fillpoly(5,points1);


    //determine whether paddle and ball collide
    if (ball_pos[1] > paddle1_pos-HALF_PAD_HEIGHT -2 && ball_pos[1]<paddle1_pos +HALF_PAD_HEIGHT +2 && ball_pos[0] - BALL_RADIUS <= PAD_WIDTH+2)
{
	ball_vel[0] = -ball_vel[0];
	ball_vel[1] = ball_vel[1];
	score1+=1;
	s1=score1;
	if(score1==max_score)
	{
	ball_pos[0]=WIDTH/2;
	ball_pos[1]=HEIGHT/2;
	ball_vel[0]=0;
	ball_vel[1]=0;

	//outtextxy(320,240,"PLAYER 1 WINS....ENTER R TO QUIT");

	}
	itoa(score1,str,10);



}
    if (ball_pos[1] > paddle2_pos-HALF_PAD_HEIGHT -2 && ball_pos[1] < paddle2_pos +HALF_PAD_HEIGHT+2 && WIDTH - (WIDTH - (ball_pos[0] + BALL_RADIUS)) >= (WIDTH - PAD_WIDTH) -2){

	ball_vel[0] = -ball_vel[0];

	ball_vel[1] = ball_vel[1];
	score2+=1;
	s2=score2;
	if(score2==max_score)
	{
	ball_pos[0]=WIDTH/2;
	ball_pos[1]=HEIGHT/2;
	ball_vel[0]=0;
	ball_vel[1]=0;
	}
	itoa(score2,str1,10);


}

settextstyle(1,0,1);
outtextxy(160,90,str);
settextstyle(2,0,6);
outtextxy(140,50,"PLAYER 1");
settextstyle(1,0,1);
outtextxy(480,90,str1);
settextstyle(2,0,6);
outtextxy(440,50,"PLAYER 2");

if(s2==max_score || s1==max_score)
{
if(s2>s1){
settextstyle(3,0,2);
outtextxy(380,280,"PLAYER 2 WINS !!");
//outtextxy(50,280,"GAME OVER...ENTER R TO EXIT!!");
}
else if(s2<s1){

settextstyle(3,0,2);
outtextxy(100,280,"PLAYER 1 WINS !!");
//outtextxy(360,280,"GAME OVER...ENTER R TO EXIT");
}

}
//flag=1;

if(kbhit())
{   char ch=getche();

    switch(ch){

    case 'w':
    case 'W':
	paddle1_vel = -4;
	paddle2_vel=0;
	break;

    case 's':
    case 'S':
	paddle1_vel = 4;
	paddle2_vel=0;
	break;

    case '-':
	paddle2_vel = -4;
	paddle1_vel=0;
	break;

    case '+':
	paddle2_vel = 4;
	paddle1_vel=0;
	break;


    case 'r':
    case 'R':
	cpad=0;
	break;

    default:
	paddle1_vel=0;
	paddle2_vel=0;
}
}
else{
paddle1_vel=0;
paddle2_vel=0;
}
//key strokes
delay(15);

cleardevice();



setcolor(WHITE);
line(WIDTH/2,0,WIDTH/2,HEIGHT);
line(PAD_WIDTH,0,PAD_WIDTH,HEIGHT);
line(WIDTH-PAD_WIDTH,0,WIDTH-PAD_WIDTH,HEIGHT);



}
getch();
closegraph();
}
