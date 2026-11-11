#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

string c1, s1, c2, s2;
char a[10] = {0, 0, 0, 1, 1};

int main()
{
	freopen("travel.in" ,"r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2)
	{
		cout << "0000";
		return 0;
	}
	else 
	{
		if ((s1[0] != s2[0] || s1[1] != s2[1]))
		{
			cout << "1000";
		}
		else 
		{
			if (a[s1[2] - 'A'] != a[s2[2] - 'A'])
			{
				cout << "1100";
			}
			else
			{
				if (abs(s1[2] - s2[2]) <= 1)
				{
					cout << "1111";
				}
				else
				{
					cout << "1110";
				}
			}
		}
	}
	return 0;
}
