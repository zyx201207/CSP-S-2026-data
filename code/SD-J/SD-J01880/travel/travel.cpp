#include<bits/stdc++.h>
using namespace std;
#define N 2010
void Freopen()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	return ;
}
char a[N],b[N],c[N],d[N];
int t1,t2;
int q1,q2;
char c1,c2;
int main()
{
	Freopen();
	scanf("%s%s%s%s",a+1,b+1,c+1,d+1);
	t1=0,t2=0;
	if(a[1]=='0') t1=a[2]-'0';
	else t1=(a[1]-'0')*10+(a[2]-'0');
	if(c[1]=='0') t2=c[2]-'0';
	else t2=(c[1]-'0')*10+(c[2]-'0');
	if(t1!=t2) 
	{
		printf("0000\n");
		return 0;
	}
	if(b[1]=='0') q1=b[2]-'0';
	else q1=(b[1]-'0')*10+(b[2]-'0');
	if(d[1]=='0') q2=d[2]-'0';
	else q2=(d[1]-'0')*10+(d[2]-'0');
	if(q1!=q2)
	{
		printf("1000\n");
		return 0;
	}
	c1=b[3],c2=d[3];
	if(c1<='C'&&c2<='C'||c1>'C'&&c2>'C')
	{
		if(c1-c2==1||c2-c1==1) printf("1111\n");
		else printf("1110\n");	
	}else{
		printf("1100\n");
	} 
	return 0;
}
