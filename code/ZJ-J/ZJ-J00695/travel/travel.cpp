#include<bits/stdc++.h>
using namespace std;
char c1[5],s1[10];
char c2[5],s2[10];
int main()
{
	freopen("travle.in","r",stdin);
	freopen("travle.out","w",stdout);
	for(int i=1;i<=2;i++)cin>>c1[i];
	getchar();
	for(int i=1;i<=3;i++)cin>>s1[i];
	getchar();
	for(int i=1;i<=2;i++)cin>>c2[i];
	getchar();
	for(int i=1;i<=3;i++)cin>>s2[i];
	
	for(int i=1;i<=2;i++)
	{
		if(c1[i]!=c2[i])
		{
			printf("0000");
			return 0;
		}
	}
	printf("1");
	for(int i=1;i<=2;i++)
	{
		if(s1[i]!=s2[i])
		{
			printf("000");
			return 0;
		}
	}
	printf("1");
	if(s1[3]=='A')
	{
		if(s2[3]=='B'||s2[3]=='C')
		{
			printf("1");
			if(s2[3]=='B')
			{
				printf("1");
			}
			else printf("0");
		}
		else
		{
			printf("00");
			return 0;
		}
	}
	if(s1[3]=='B')
	{
		if(s2[3]=='A'||s2[3]=='C')
		{
			printf("11");
		}
		else
		{
			printf("00");
			return 0;
		}
	}
	if(s1[3]=='C')
	{
		if(s2[3]=='A'||s2[3]=='B')
		{
			printf("1");
			if(s2[3]=='B')
			{
				printf("1");
			}
			else printf("0");
		}
		else
		{
			printf("00");
			return 0;
		}
	}
	if(s1[3]=='D')
	{
		if(s2[3]=='E')
		{
			printf("11");
		}
		else
		{
			printf("00");
			return 0;
		}
	}
	if(s1[3]=='E')
	{
		if(s2[3]=='D')
		{
			printf("11");
		}
		else
		{
			printf("00");
			return 0;
		}
	}
	return 0;
}