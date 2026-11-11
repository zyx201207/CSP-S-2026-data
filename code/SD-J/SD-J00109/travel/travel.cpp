#include <bits/stdc++.h>
using namespace std;
int a,b;
char sa[5],sb[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%s%d%s",&a,&sa,&b,&sb);
	if(a==b)
	{
		printf("1");
		if(sa[0]==sb[0]&&sa[1]==sb[1])
		{
			printf("1");
			if((sa[2]=='B'&&sb[2]=='D')||(sa[2]=='C'&&sb[2]=='D')||(sa[2]=='C'&&sb[2]=='E')) printf("00");
			else if((sb[2]=='B'&&sa[2]=='D')||(sb[2]=='C'&&sa[2]=='D')||(sb[2]=='C'&&sa[2]=='E')) printf("00");
			else
			{
				printf("1");
				if(abs(sa[2]-sb[2])==1) printf("1");
				else printf("0");
			}
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
}
