#include <bits/stdc++.h>
using namespace std;
long long c1, c2;
string s1, s2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) 
	{
		cout << 1 << " ";
		if (s1[2] + 'A' == s2[2] + 'B')
		{
			cout << 1 << " ";
			if ((s1[0] == s2[0]) && (s1[1] = s1[2])) 
			{
				cout << 1 << " ";
			}
		}
		
	}
	return 0;
}