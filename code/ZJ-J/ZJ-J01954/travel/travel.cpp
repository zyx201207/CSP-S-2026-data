#include<bits/stdc++.h>
using namespace std;
short a1,b1;
string a2,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)
	{
		printf("1");
		if((a2[0]-48)*10+a2[1]==(b2[0]-48)*10+b2[1])
		{
			printf("1");
			if(a2[2]-65<3&&b2[2]-65<3||a2[2]-65>2&&b2[2]-65>2)
			{
				printf("1");
				if(abs(a2[2]-b2[2])==1)
					printf("1");
				else
					printf("0");
			}
			else
				printf("00");
		}
		else
			printf("000");
	}
	else
		printf("0000");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
