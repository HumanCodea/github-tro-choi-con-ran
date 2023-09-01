#include <iostream>
#include "libruary.h"
 
using namespace std;
int s1 = 3;
#define MAX 100


void xoacontro()
{
 CONSOLE_CURSOR_INFO Info;
 Info.bVisible = FALSE;
 Info.dwSize = 20;
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void vetuong_tren(){
	int x = 10;
	int y = 1;
	while(x < 100){
	  gotoXY(x, y);
	  cout << "-";
	  x++;
	}
	
}

void vetuong_duoi(){
	int x = 10;
	int y = 26;
	while(x < 100){
	  gotoXY(x, y);
	  cout << "-";
	  x++;
	}
	
}

void vetuong_trai(){
	int x = 10;
	int y = 1;
	while(y < 26){
	  gotoXY(x, y);
	  cout << "|";
	  y++;
	}
	
}

void vetuong_phai(){
	int x = 100;
	int y = 1;
	while(y < 26){
	  gotoXY(x, y);
	  cout << "|";
	  y++;
	}
	
}

void vetuong(){
	vetuong_tren();
	vetuong_duoi();
	vetuong_trai();
	vetuong_phai();
}

void khoitao_ran(int toadox[], int toadoy[]){
	int x = 50, y = 13;
	for(int i = 0; i < s1; i++){
		toadox[i] = x;
		toadoy[i] = y;
		x--;
	}
}

void ve_ran(int toadox[], int toadoy[]){
	for(int i = 0; i < s1; i++){
		gotoXY(toadox[i], toadoy[i]);
		if(i == 0){
			cout << "0";
		} else {
			cout << "o";
		}
	}
}

void xoa_ran(int toadox[], int toadoy[]){
	   for(int i = 0; i <s1; i++){
	   	gotoXY(toadox[i], toadoy[i]);
	      cout << " ";
	   }
}

void them(int a[], int x){
	for(int i = s1; i > 0; i--){
		a[i] = a[i-1];
	}
	a[0] = x;
	s1++;
}

void xoa(int a[], int vt){
	for(int i = vt; i < s1; i++){
		a[i] = a[i+1];
	}
	s1--;
}

bool kt_ran_chen_qua(int xqua, int yqua, int toadox[], int toadoy[]){
	for(int i = 0; i < s1; i++){
		if((xqua == toadox[i]) && (yqua == toadoy[i])){
			return true;
		}
	}
	return false;
}

bool kiemtraran_an_qua(int xqua,int yqua, int x0,int y0){
	if((xqua == x0) && (yqua == y0)){
		return true;
	}
	return false;
}

void toa_qua(int &xqua, int &yqua, int toadox[], int toadoy[]){
	do{
	// 11 <= xqua << 99
	xqua = rand() % (99 - 11 + 1) + 11;
	// 2 <= yqua <= 25
	yqua = rand() % (25 - 2 + 1) + 2;
	}while(kt_ran_chen_qua(xqua, yqua, toadox, toadoy) == true);
	int i = rand() % (15 - 1 + 1) + 1;
	gotoXY(xqua, yqua);
	SetColor(i);
	cout << "*";
    SetColor(7);
}

void xu_ly_ran(int toadox[], int toadoy[], int x, int y,int &xqua, int &yqua){
	them(toadox, x);
	them(toadoy, y);
	if(kiemtraran_an_qua(xqua,yqua,toadox[0],toadoy[0]) == false){
		xoa(toadox, s1 - 1);
	    xoa(toadoy, s1 - 1);
	} else {
		s1--;
		toa_qua(xqua,yqua,toadox,toadoy);
		
	}
	ve_ran(toadox, toadoy);
}

bool kiemtra_ran_cham_tuong(int x0, int y0){
	if( y0 == 1 && (x0 >= 10 && x0 <= 100)){
		return true;
	}
	
	if( y0 == 26 && (x0 >= 10 && x0 <= 100)){
		return true;
	}
	
	if( x0 == 10 && (y0 >= 1 && y0 <= 26)){
		return true;
	}
	
	if( x0 == 100 && (y0 >=1 && y0 <= 26)){
		return true;
	}
	return false;
}

bool kiemtra_ran_can_duoi(int toadox[], int toadoy[]){
	for(int i = 1; i < s1; i++){
		if((toadox[0] == toadox[i]) && (toadoy[0] == toadoy[i])){
			return true;
		}
	}
	return false;
}

bool kt_ran(int toadox[], int toadoy[]){
	bool kt1 = kiemtra_ran_can_duoi(toadox, toadoy);
	bool kt2 = kiemtra_ran_cham_tuong(toadox[0], toadoy[0]);
		if(kt1 == true || kt2 == true){
		   return true;
	    }
	    return false;
}


int main(){
	srand(time(NULL));
	bool Gameover = false;
	int toadox[MAX];
	int toadoy[MAX];
	khoitao_ran(toadox, toadoy);
	ve_ran(toadox, toadoy);
	vetuong();
	xoacontro();
	int xqua = 0, yqua = 0;
	toa_qua(xqua,yqua,toadox,toadoy);
	int check = 2;
	int x= 50,y = 13;
	int i = 1;
	while(Gameover == false){
		if(_kbhit()){
			char kitu = _getch();
			if(kitu == -32){
				kitu = _getch();
				if(kitu == 72 && check != 0){
				check = 1;
			} else if (kitu == 80 && check != 1) {
				check = 0;
			} else if(kitu == 75 && check != 2){
				check = 3;
			} else if(kitu == 77 && check != 3){
				check = 2;
			}
			}
		}
		if(check == 0 ){
	    	y++;
	    	Sleep(100);
		} else if(check == 1 ){
			y--;
			Sleep(100);
		} else if(check == 2 ){
			x++;
		} else if(check == 3 ){
			x--;
		}
		xoa_ran(toadox, toadoy);
		xu_ly_ran(toadox, toadoy, x, y,xqua,yqua);
	    Gameover = kt_ran(toadox, toadoy);
		Sleep(150);
	}
	_getch();
    return 0;	
}
