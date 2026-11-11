#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 10;

string c1, s1, c2, s2;

signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
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
	bool ok = false;
	if(s1[0] == s2[0] && s1[1] == s2[1])
	{
		ok = true;
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	char a = s1[2], b = s2[2];
	if(ok == true && ((a == 'A' && b == 'B') || (a == 'A' && b == 'C') || (a == 'B' && b == 'C') || (a == 'B' && b == 'A') || (a == 'C' && b == 'A') || (a == 'C' && b == 'B') || (a == 'D' && b == 'F')|| (a == 'F' && b == 'D')))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if(ok == true && ((a == 'A' && b == 'B') || (a == 'B' && b == 'A') || (a == 'B' && b == 'C') || (a == 'C' && b == 'B') || (a == 'D' && b == 'F') || (a == 'F' && b == 'D')))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
