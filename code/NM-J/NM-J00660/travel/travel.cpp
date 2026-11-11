#include<bits/stdc++.h>
using namespace std;
long long ax,ay,bx,by;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%lld %lld",&ax,&ay);
	cin>>a;
	scanf("%lld %lld",&bx,&by);
	cin>>b;
	long long R,X;
	if(a=='A'||a=='B'||a=='C'){
		R=0;
	}else{
		R=1;
	}
	if(b=='A'||b=='B'||b=='C'){
		X=0;
	}else{
		X=1;
	}
	if(ax==bx){
		printf("1");
		if(ay==by){
			printf("1");
			if(R==X){
				printf("1");
				char la=a,lb=b;
				if(la>lb){
					swap(la,lb);
				}
				if((la=='A'&&lb=='B')||(la=='B'&&lb=='C')||(la=='D'&&lb=='F')){
					printf("1");
				}else{
					printf("0");
				}
			}else{
				printf("00");
			}
		}else{
			printf("000");
		}
	}else{
		printf("0000");
	}
	return 0;
}
