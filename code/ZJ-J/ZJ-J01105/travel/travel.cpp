#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char e,f;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	ret=((ch&15)<<3)+((getchar()&15)<<1);
	return ret;
}
//char red(){
//	char ch=getchar();
//	while('A'>=ch||'F'<=ch)ch=getchar();
//	return ch;
//}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a=read(),c=read();cin>>e;
	b=read(),d=read();cin>>f;
	if(a==b)printf("%d",1);else{
		printf("%d%d%d%d\n",0,0,0,0);
		return 0;
	}
	if(c==d)printf("%d",1);else{
		printf("%d%d%d\n",0,0,0);
		return 0;
	}
	if(e=='D'&&f=='F'||e=='F'&&f=='D'){printf("%d%d\n",1,1);return 0;}
	if(e=='D'||f=='F'||e=='F'||f=='D'){printf("%d%d\n",0,0);return 0;}
	printf("%d",1);
	if(e-f==1||e-f==-1)printf("%d\n",1);else printf("%d\n",0);
	return 0;
}
