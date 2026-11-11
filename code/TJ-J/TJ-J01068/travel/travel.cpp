#include<bits/stdc++.h>
using namespace std;
char box1[2],box2[2],seat1[3],seat2[3];
bool side(char x,char y){
	bool a,b;
	if(x=='A'||x=='B'||x=='C') a=1;
	if(x=='D'||x=='F') a=0;
	if(y=='A'||y=='B'||y=='C') b=1;
	if(y=='D'||y=='F') b=0;
	return a^b;
}
bool nex(char x,char y){
	int a,b;
	a=x-'A',b=y-'A';
	if(abs(a-b)==1) return 0;
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<2;i++) box1[i]=getchar_unlocked();
	getchar_unlocked();
	for(int i=0;i<3;i++) seat1[i]=getchar_unlocked();
	getchar_unlocked();
	for(int i=0;i<2;i++) box2[i]=getchar_unlocked();
	getchar_unlocked();
	for(int i=0;i<3;i++) seat2[i]=getchar_unlocked();
	if(box1[0]!=box2[0]||box1[1]!=box2[1]){
		__builtin_puts("0000");
	}else{
		if(seat1[0]!=seat2[0]||seat1[1]!=seat2[1]){
			__builtin_puts("1000");
		}else{
			if(side(seat1[2],seat2[2])){
				__builtin_puts("1100");
			}else{
				if(nex(seat1[2],seat2[2])){
					__builtin_puts("1110");
				}else{
					__builtin_puts("1111");
				}
			}
		}
	}
	return 0;
}
