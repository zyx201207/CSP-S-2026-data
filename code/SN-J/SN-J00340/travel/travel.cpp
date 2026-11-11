#include <bits/stdc++.h>
using namespace std;
int num,num1;
int c,c1;
char s,s1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d%c%d%d%c",&num,&c,&s,&num1,&c1,&s1);
	if (num==num1)
	{
		printf("1");
		if (c==c1)
		{
			cout<<1;
			if ((s=='D' &&s1=='A')||(s=='D' &&s1=='B')||(s=='D' &&s1=='C')||(s=='F' &&s1=='A')||(s=='F' &&s1=='B')||(s=='F' &&s1=='C')||(s1=='D' &&s=='A')||(s1=='D' &&s=='B')||(s1=='D' &&s=='C')||(s1=='F' &&s=='A')||(s1=='F' &&s=='B')||(s1=='F' &&s=='C'))printf("00");
			else
			{
				printf("1");
				if (s+1==s1-0 ||s1+1==s-0)printf("1");
				else printf("0");
			}
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
}
