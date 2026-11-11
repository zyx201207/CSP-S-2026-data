#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ca,cb;
	char sa[5],sb[5];
	scanf("%d%s%d%s",&ca,sa,&cb,sb);
	if(ca==cb)
		printf("1");
	else
	{
		printf("0000");
		return 0;
	}
	if(sa[0]==sb[0]&&sa[1]==sb[1])
		printf("1");
	else
	{
		printf("000");
		return 0;
	}
	if((sa[2]=='A'&&sb[2]=='B')||(sa[2]=='B'&&sb[2]=='A')||(sa[2]=='A'&&sb[2]=='C')||(sa[2]=='C'&&sb[2]=='A')||(sa[2]=='B'&&sb[2]=='C')||(sa[2]=='C'&&sb[2]=='B')||(sa[2]=='D'&&sb[2]=='E')||(sa[2]=='E'&&sb[2]=='D'))
		printf("1");
	else
	{
		printf("00");
		return 0;
	}
	if(abs((int)sa[2]-sb[2])==1)
		printf("1");
	else
		printf("0");
	return 0;
}
