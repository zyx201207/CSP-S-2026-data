#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=s1[2]-'A'+1;
	b=s2[2]-'A'+1;
	if(a>3)
		a+=2;
	if(b>3)
		b+=2;
	if(a>b)
		swap(a,b);
	if(c1==c2)
	{
		printf("1");
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			printf("1");
			if(a+1==b||a+2==b)
			{
				printf("1");
				if(a+1==b)
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
	return 0;
}
