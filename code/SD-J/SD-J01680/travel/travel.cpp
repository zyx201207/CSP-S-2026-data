#include<bits/stdc++.h>
using namespace std;

string s1,s2,c1,c2;
int ce1[10],ce2[10];

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		printf("1");
	}
	else
	{
		printf("0000");
		return 0;
	}
	string a,b;
	a+=s1[0];
	a+=s1[1];
	
	b+=s2[0];
	b+=s2[1];
	if(a==b)
	{
		printf("1");
	}
	else
	{
		printf("000");
		return 0;
	}
	if(s1[2]>='A'&&s1[2]<='C')
	{
		ce1[1]++;
	}
	else
	{
		ce1[0]++;
	}
	if(s2[2]>='A'&&s2[2]<='C')
	{
		ce2[1]++;
	}
	else
	{
		ce2[0]++;
	}
	if(ce1[0]!=0&&ce2[0]!=0)
	{
		printf("1");
	}
	else if(ce1[1]!=0&&ce2[1]!=0)
	{
		printf("1");
	}
	else
	{
		printf("00");
		return 0;
	}
	char a1=s1[2],a2=s2[2];
	if(a1=='A'&&a2=='B')
	{
		printf("1");
	}
	else if(a1=='B'&&a2=='C')
	{
		printf("1");
	}
	else if(a1=='D'&&a2=='F')
	{
		printf("1");
	}
	else
	{
		printf("0");
		return 0;
	}
	return 0;
}
