#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
bool gameover;
const int width = 30;
const int hieght = 20;
int x, y, fruitx, fruity, score;
enum eDirection {STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
int tailx[100], taily[100];
int ntail;
void setup(){
	gameover = false;
	dir=STOP;
	x =  width/2;
	y = hieght/2;
	fruitx = rand() % width;
	fruity = rand() % hieght;
	score = 0;
}

void draw(){
	system("cls");
	for(int i=0;i<width+2;i++){
		cout<<"#";
	}
	cout<<endl;
	
	for(int i=0;i<width;i++){
		for(int j=0;j<width;j++){
			if(j==0){
				cout<<"#";
			}
			if(i==y and j==x){
				cout<<"O";
			}
			else if(i==fruity and j==fruitx){
				cout<<"F";
			}
			else{
				bool print = false;
				for(int k=0;k<ntail;k++){
					if(tailx[k]==j && taily[k]==i){
						cout<<"o";
						print = false;
					}
				}
				if(!print){
					cout<<" ";
				}
			}
			
			if(j==width-1){
				cout<<"#";
			}
		}
		cout<<endl;
	}
	
	for(int i=0;i<width+2;i++){
		cout<<"#";
	}
	cout<<endl;
	cout<<"SCORE:"<<score;
}

void input(){
	if(_kbhit()){
		switch(_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'q':
			gameover = true;
			break;	
		}
	}
}

void logic(){
	
	int prevx = tailx[0];
	int prevy = taily[0];
	int prev2x, prev2y;
	tailx[0] = x;
	taily[0] = y;
	for(int i=1;i<ntail;i++){
		prev2x = tailx[i];
		prev2y = taily[i];
		tailx[i] = prevx;
		taily[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
	}
	
    switch(dir)
	{
	case LEFT:
	  	x--;
	  	break;
	case RIGHT:
  		x++;
	  	break;
	case UP:
	  	y--;
		break;
	case DOWN:
	  	y++;
	  	break;
	default:
	  	break;
	}
	if(x>width || x<0 || y>hieght || y<0){
		gameover= true;
	}
	
	for(int i=0;i<ntail;i++){
		if(tailx[i]==x && taily[i]==y){
			gameover = true;
		}
	}
	
	if(x==fruitx and y==fruity){
		score = score+10;
		fruitx = rand() % width;
		fruity = rand() % hieght;
		ntail++;
	}
}

int main(){
	setup();
	while(!gameover){
		draw();
		input();
		logic();
	}
	return 0;
}
