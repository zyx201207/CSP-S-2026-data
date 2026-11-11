#include<bits/stdc++.h>
using namespace std;
int r,x,sr,sx;
char rs[10],xs[10],R,X;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	r=read();
	scanf("%s",rs+1);
	x=read();
	scanf("%s",xs+1);
	if(r!=x){printf("0000");return 0;}
	printf("1");
	sr=(rs[1]-'0')*10+rs[2]-'0';
	sx=(xs[1]-'0')*10+xs[2]-'0';
	if(sr!=sx){printf("000");return 0;}
	printf("1");
	R=rs[3],X=xs[3];
	if('A'<=R&&R<='C'&&'A'<=X&&X<='C') printf("1");
	else if('D'<=R&&R<='F'&&'D'<=X&&X<='F') printf("1");
	else{printf("00");return 0;}
	if(abs(R-X)==1) printf("1");
	else printf("0");
	return 0;
}