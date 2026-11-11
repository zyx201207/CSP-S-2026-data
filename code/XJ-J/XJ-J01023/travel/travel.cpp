#include<bits/stdc++.h>
using namespace std;
int a1[3],b1[4],a2[3],b2[4];
int main()
{
	string c1,s1,c2,s2;
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	for(int i=1;i<=2;i++)
	{
		a1[i]=c1[i-1]-'0';
		a2[i]=c2[i-1]-'0';
		if(a1[i]!=a2[i])
		{
			cout << "0000";
			return 0;
		}
	}
	for(int i=1;i<=3;i++)
	{
		b1[i]=s1[i-1]-'0';
		b2[i]=s2[i-1]-'0';
	}
	if(b1[1]!=b2[1])
	{
		cout << "1000";
		return 0;
	}
	else
	{
		if(b1[2]!=b2[2])
		{
			cout << "1000";
			return 0;
		}
	}
	if(b1[3]>19)
	{
		if(b2[3]>19)
		{
			cout << "1111";
			return 0;
		}
		else
		{
			cout << "1100";
			return 0;
		}
	}
	else
	{
		if(b2[3]>19)
		{
			cout << "1100";
			return 0;
		}
		if(b1[3]>b2[3])
		{
			if(b1[3]-1==b2[3])
			{
				cout << "1111";
				return 0;
			}
			else
			{
				cout << "1110";
				return 0;
			}
		}
		else
		{
			if(b1[3]+1==b2[3])
			{
				cout << "1111";
				return 0;
			}
			else
			{
				cout << "1110";
				return 0;
			}
		}
	}
}