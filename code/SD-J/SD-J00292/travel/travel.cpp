#include<cstdio>
#include<cstring>
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[5],b[5],c[5],d[5];
	scanf("%s%s%s%s",a,b,c,d);
	int f1=!strcmp(a,c);
	int f2=f1&&b[0]==d[0]&&b[1]==d[1];
	int x=b[2]<='C',y=d[2]<='C';
	int f3=f2&&x==y;
	int p1,p2;
	if(b[2]=='A')p1=0;
	else if(b[2]=='B')p1=1;
	else if(b[2]=='C')p1=2;
	else if(b[2]=='D')p1=0;
	else p1=1;
	if(d[2]=='A')p2==0;
	else if(d[2]=='B')p2=1;
	else if(d[2]=='C')p2=2;
	else if(d[2]=='D')p2=0;
	else p2=1;
	int f4=f3&&(p1-p2==1||p2-p1==1);
	printf("%d%d%d%d\n",f1,f2,f3,f4);
	return 0;
	
} 
