#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int cnt;
int a;
int main()
{
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << 1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	for(int i = 0;i < 2;i++)
	{
		if(s1[i] == s2[i])
		{
			cnt++;
		}
	}
	if(cnt == 2)
	{
		cout << 1;

	}
	else
	{
		cout << "1000";
		return 0;
	}
	if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C' && s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
	{
		cout << 1;
	}
	else if(s1[2] == 'D' || s1[2] == 'F' && s2[2] == 'D' || s2[2] == 'F')
	{
		cout << 1;
	}
	else
	{
		cout << "1100";
		return 0;
	}
	if(s1[2] == s2[2] + 1 || s1[2] == s2[2] - 1 )
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
