#include<bits/stdc++.h>
using namespace std;
char a[5],b[5],c[5],d[5];
bool check(char x[5],char y[5])
{
	if(x[1]==y[1] && x[2]==y[2]) return 1;
	else return 0;
}
bool check2(char n,char m)
{
	if(n<='C' && m<='C') return 1;
	else if(n>='D' && m>='D') return 1;
	else return 0;
}
bool check3(char l,char k)
{
	if(abs(k-l)==1) return 1;
	else return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",a+1,b+1,c+1,d+1);
	if(check(a,c)==0)
	{
		printf("0000");
		return 0;
	}
	else printf("1");
	if(check(b,d)==0)
	{
		printf("000");
		return 0;
	}
	else printf("1");
	if(check2(b[3],d[3])==0)
	{
		printf("00");
		return 0;
	}
	else printf("1");
	if(check3(b[3],d[3])==0)
	{
		printf("0");
		return 0;
	}
	else printf("1");
	return 0;
}
