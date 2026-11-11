#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	int i;
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	for(i=0;i<2;i++)
	{
		if(c1[i]!=c2[i])
		{
			printf("0000");
			return 0;
		}
	}
	printf("1");
	int f1=0;
	for(i=0;i<2;i++)
	{
		if(s1[i]!=s2[i])
		{
			printf("000");
			return 0;
		}
	}
	printf("1");
	int f2=0;
	if(s1[2]>='A'&&s1[2]<='C')
	{
		f1=1;
	}
	if(s2[2]<='C'&&s2[2]>='A')
	{
		f2=1;
	}
	if(f1==f2)
	{
		printf("1");
		if(f1==0)
		{
			printf("1");
			return 0;
		}
		if(s1[2]=='B'||s2[2]=='B')
		{
			printf("1");
			return 0;
		}
	}
	printf("00");
	return 0;
}