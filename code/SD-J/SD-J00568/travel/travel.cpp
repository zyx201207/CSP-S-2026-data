#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if (ch == '-')
		{
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int main()
{

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int f = 0;
	if (c1 == c2)
	{
		cout << 1;
		f++;
	}
	else
	{
		cout<<0;
	}
	if ((s1[0] -'0') * 10 + s1[1] == (s2[0] -'0') * 10 + s2[1] && f == 1)
	{
		cout<<1;
		f++;
	}
	else
	{
		cout<<0;
	}
	if(((s1[2] > 'C' && s2[2] > 'C') || (s1[2] <=  'C' && s2[2] <= 'C')) && f == 2)
	{
		cout<<1;
		f++;
	}
	else
	{
		cout<<0;
	}
	if(((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'F' && s2[2] == 'D')) && f == 3)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}



