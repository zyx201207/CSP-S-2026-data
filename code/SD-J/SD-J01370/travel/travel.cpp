#include<bits/stdc++.h>
using namespace std;
string sa,ta,sb,tb; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sa>>ta>>sb>>tb;
	if(sa==sb)
	{
		printf("1");
		if(ta[0]==tb[0]&&ta[1]==tb[1])
		{
			printf("1");
			if((ta[2]=='D'&&tb[2]=='F')||(ta[2]=='F'&&tb[2]=='D'))
			{
				printf("11");
			}
			else if(ta[2]>='A'&&ta[2]<='C'&&tb[2]>='A'&&tb[2]<='C')
			{
				printf("1");
				if(ta[2]=='B'||tb[2]=='B')
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
