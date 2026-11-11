#include<bits/stdc++.h>
using namespace std;
long long int c1,c2;
char s1[5],s2[5],v[10];
int fun()
{
	for(int i=1;i<=2;i++)
	if(s1[i]!=s2[i])
	return 0;
	return 1;
}
int fun1()
{
	if('A'<=s1[3]&&'C'>=s1[3])
	if('A'<=s2[3]&&'C'>=s2[3])
	return 1;
	if('D'<=s1[3]&&'F'>=s1[3])
	if('D'<=s2[3]&&'F'>=s2[3])
	return 1;
	return 0;
}
int fun2()
{
	for(int i=0;i<5;i++)
	{
		if(v[i]==s1[3]&&v[i+1]==s2[3])
		return 1;
		if(v[i]==s2[3]&&v[i+1]==s1[3])
		return 1;

	}
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long int i;
	for(i=0;i<5;i++)
	{
		v[i]='A'+i;
	}
	cin>>c1;
	for(i=1;i<=3;i++)
	{
		cin>>s1[i];
	}
	cin>>c2;
	for(i=1;i<=3;i++)
	{
		cin>>s2[i];
	}
	if(c1==c2)
	{
		cout<<1;
		if(fun()==1)
		{
			cout<<1;
			if(fun1()==1)
			{
				cout<<1;
				if(fun2()==1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
					return 0;
				}
			}
			else
			{
				for(i=1;i<=2;i++)
				cout<<0;
				return 0;
			}
		}
		else
		{
			for(i=1;i<=3;i++)
			cout<<0;
			return 0;
		}
	}
	else
	{
		for(i=1;i<=4;i++)
		cout<<0;
		return 0;
	}
	return 0;
}