#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
char s1[9],s2[9],out[7],seatLetter1,seatLetter2;
bool isSeatOnTheSameSide=false,oneIsOnRight=false,twoIsOnRight=false;
int readCharSeats(char seat,int cloned){
	if(seat=='1') cloned+=1;
	if(seat=='2') cloned+=2;
	if(seat=='3') cloned+=3;
	if(seat=='4') cloned+=4;
	if(seat=='5') cloned+=5;
	if(seat=='6') cloned+=6;
	if(seat=='7') cloned+=7;
	if(seat=='8') cloned+=8;
	if(seat=='9') cloned+=9;
	return cloned;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,clonedSeatNumber1=0,clonedSeatNumber2=0;
	cin>>c1;
	scanf("%s",s1);
	cin>>c2;
	scanf("%s",s2);
	//for(int i=0; i<2; i++) {
		if(s1[0]=='1') clonedSeatNumber1+=10;
		clonedSeatNumber1=readCharSeats(s1[1],clonedSeatNumber1);
		if(s2[0]=='1') clonedSeatNumber2+=10;
		clonedSeatNumber2=readCharSeats(s2[1],clonedSeatNumber2);
	//}
	seatLetter1=s1[2];
	seatLetter2=s2[2];
	if(seatLetter1=='D'||seatLetter1=='F') oneIsOnRight=true;
	if(seatLetter2=='D'||seatLetter2=='F') twoIsOnRight=true;
	if(oneIsOnRight==twoIsOnRight) isSeatOnTheSameSide=true;
	
	if(c1==c2) out[0]='1';
	if(clonedSeatNumber2==clonedSeatNumber1) out[1]='1';
	if(isSeatOnTheSameSide&&out[1]=='1') out[2]='1';
	//分情况讨论
	if(oneIsOnRight&&twoIsOnRight) out[3]='1';
	if(oneIsOnRight==false&&twoIsOnRight==false){
		if(seatLetter1=='A'&&seatLetter2=='B') out[3]='1';
		if(seatLetter1=='B'||seatLetter2=='B') out[3]='1';
		if(seatLetter1=='C'&&seatLetter2=='B') out[3]='1';
		if(seatLetter1=='B'&&seatLetter2=='A') out[3]='1';
		if(seatLetter1=='B'&&seatLetter2=='C') out[3]='1';
	}
	for(int i=0;i<4;i++){
		if(out[i]!='1') out[i]='0';
		if(out[i]=='0'){
			while(i<4){
				out[i]='0';
				i++;
			}
		}
	}
	
	printf("%s",out);
	return 0;
}

