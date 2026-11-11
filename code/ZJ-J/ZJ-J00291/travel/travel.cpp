#include<bits/stdc++.h>
using namespace std;
int c1,c21,c22,c3,c41,c42;
string s;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(cin,s);
	c1=(int)(s[0]-'0')*10+(int)(s[1]-'0');
	c21=(int)(s[3]-'0')*10+(int)(s[4]-'0');
	c22=(int)(s[5]-'A');
	c3=(int)(s[7]-'0')*10+(int)(s[8]-'0');
	c41=(int)(s[10]-'0')*10+(int)(s[11]-'0');
	c42=(int)(s[12]-'A');
	if(c1!=c3)
	{
		printf("0000");
	}
	else 
	{
		if(c21!=c41)
		{
			printf("1000");
		}
		else
		{
			if((c22<=2&&c42<=2)||(c22>2&&c42>2))
			{
				if(c22-c42==1||c42-c22==1)
				{
					printf("1111");
				}
				else
				{
					printf("1110");
				}
			}
			else
			{
				printf("1100");
			}
		}
	}
	return 0;
}