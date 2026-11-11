#include<bits/stdc++.h>
using namespace std;
char c1[5],s1[5],c2[5],s2[5];
int che1=0,che2=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c1,s1,c2,s2);
	for(int i=0;i<2;i++)
	{
		che1=che1*10+c1[i];
		che2=che2*10+c2[i];
	}
	if(che1==che2)
	{
		printf("1");
		che1=0;
		che2=0;
		for(int i=0;i<2;i++)
		{
			che1=che1*10+s1[i];
			che2=che2*10+s2[i];
		}
		if(che1==che2)
		{
			printf("1");
			if((((s1[2]-'A'+1)<=3)&&((s2[2]-'A'+1)>=4))||(((s2[2]-'A'+1)<=3)&&((s1[2]-'A'+1)>=4)))
			{
				printf("00");
			}
			else
			{
				printf("1");
				if(abs((s1[2]-'A'+1)-(s2[2]-'A'+1))<=1)
				{
					printf("1");
				}
				else
				{
					printf("0");
				}
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
	return 0;
}