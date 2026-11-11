#include <bits/stdc++.h>
using namespace std;
long long r1,r2,x1,x2;
char r3,x3;
int main()
{

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%lld %lld%c %lld %lld%c",&r1,&r2,&r3,&x1,&x2,&x3);
	if(r1==x1)
	{
		printf("1");
		if(r2==x2)
		{
			printf("1");
			if((r3<='C' and x3<='C') or (r3>='D' and x3>='D'))
			{
				printf("1");
				if(abs(r3-x3)==1)
				{
					printf("1");
				}
				else
				{
					printf("0");
				}
			}else
			{
				printf("00");
			}
			
		}
		else
		{
			printf("000");
		}
	}
	else
	{
		printf("0000");
	}
	printf("\n");
	return 0;
}