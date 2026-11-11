#include <bits/stdc++.h>
using namespace std;
int n1, n2;
string s1, s2;
bool f = 0;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n1 >> s1 >> n2 >> s2;
	if (n1 == n2)
	{
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[1])
		{
			cout << "1";
			char c1 = s1[2], c2 = s2[2];
			if (c1 == 'A')
			{
				if (c2 == 'B' || c2 == 'C')
				{
					cout << "1";
					f = 1;
				}
				else cout << "1100";
			}
			else if (c1 == 'B')
			{
				if (c2 == 'A' || c2 == 'C')
				{
					cout << "1";
					f = 1;
				}
				else cout << "00";
			}
			else if (c1 == 'C')
			{
				if (c2 == 'A' || c2 == 'B')
				{
					cout << "1";
					f = 1;
				}
				else cout << "00";
			}
			else if (c1 == 'D')
			{
				if (c2 == 'F')
				{
					cout << "1";
					f = 1;
				}
				else cout << "00";
			}
			else
			{
				if (c2 == 'F')
				{
					cout << "1";
					f = 1;
				}
				else cout << "00";
			}
			if (f)
			{
				if (c1 == 'A' || c1 == 'C')
				{
					if (c2 == 'B') cout << "1";
					else cout << "0";
				}
				else if (c1 == 'B')
				{
					if (c2 == 'A' || c2 == 'C') cout << "1";
					else cout << "0";
				}
				else if (c1 == 'D')
				{
					if (c2 == 'F') cout << "1";
					else cout << "0";
				}
				else
				{
					if (c2 == 'D') cout << "1";
					else cout << "0";
				}
			}
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
