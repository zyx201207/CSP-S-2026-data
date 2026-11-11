#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
string ans;
bool tongce(char x,char y)
{
	if(x=='A'||x=='B'||x=='C')
	{
		if(y=='A'||y=='B'||y=='C')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if(y=='D'||y=='F')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int p1,p2;
	p1 = (s1[0]-'0')*10 + s1[1]-'0';
	p2 = (s2[0]-'0')*10 + s2[1]-'0';
	char z1,z2;
	z1 = s1[2];
	z2 = s2[2];
	if(c1==c2)
	{
		if(p1 == p2)
		{
			if(tongce(z1,z2))
			{
				if(z1-1==z2||z1+1==z2)
				{
					ans = "1111";
				}
				else
				{
					ans = "1110";
				}
			}
			else
			{
				ans = "1100";
			}
		}
		else
		{
			ans = "1000";
		}
	}
	else
	{
		ans = "0000";
	}
	cout << ans;
	return 0;
}
