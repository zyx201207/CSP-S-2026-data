#include<bits/stdc++.h>
using namespace std;
string st1,st2,st3,st4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>st1>>st2>>st3>>st4;
	if(st1==st3)
	{
		printf("1");
		if(st2[0]==st4[0]&&st2[1]==st4[1])
		{
			printf("1");
			if(st2[2]=='D'||st2[2]=='E')
			{
				if(st4[2]=='D'||st4[2]=='E') printf("11");
				else printf("00");
			}
			else
			{
				if(st4[2]=='A'||st4[2]=='B'||st4[2]=='C')
				{
					printf("1");
					if(st4[2]=='B'||st2[2]=='B') printf("1");
					else printf("0");
				}
				else printf("00");
			}
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
} 
