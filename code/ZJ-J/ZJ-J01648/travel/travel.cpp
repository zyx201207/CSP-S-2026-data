#include<bits/stdc++.h>
using namespace std;
char C1[10],C2[10],S1[10],S2[10];
bool F(char x)
{
	return x>='D';
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf(" %s %s %s %s",C1,S1,C2,S2);
	if((C1[0]==C2[0])&&(C1[1]==C2[1]))
	{
		printf("1");
		if((S1[0]==S2[0])&&(S1[1]==S2[1]))
		{
			printf("1");
			if(F(S1[2])==F(S2[2]))
			{
				printf("1");
				if(abs(S1[2]-S2[2])==1)
				{
					printf("1");
				}
				else
				{
					printf("0");
				}
			}
			else
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
	return 0;
}