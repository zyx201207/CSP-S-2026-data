#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char e,f;
int read()
{
	int ret=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-f;c=getchar();}
	while(isdigit(c))ret=(ret<<3)+(ret<<1)+(c&15),c=getchar();
	return ret*f;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a=(getchar()-'0')*10+(getchar()-'0');getchar();
	b=(getchar()-'0')*10+(getchar()-'0');e=getchar();getchar();
	c=(getchar()-'0')*10+(getchar()-'0');getchar();
	d=(getchar()-'0')*10+(getchar()-'0');f=getchar();getchar();
	if(a-c)puts("0000");
	else
	{
		putchar('1');
		if(b-d)puts("000");
		else
		{
			putchar('1');
			if(f<='C'^e<='C')puts("00");
			else
			{
				putchar('1');
				if(f==e+1||e==f+1)puts("1");
				else puts("0");
			}
		}
	}
	return 0;
}