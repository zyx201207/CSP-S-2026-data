#include <bits/stdc++.h>
#define int long long
using namespace std;
string ss1[2], ss2[2];
signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> ss1[0];
	cin >> ss1[1];
	cin >> ss2[0];
	cin >> ss2[1];
	if (ss1[0] != ss2[0])
	{
		cout << "0000\n";
		return 0;
	}
	if ((ss1[1][0] != ss2[1][0]) or (ss1[1][1] != ss2[1][1]))
	{
		cout << "1000\n";
		return 0;
	}
	if ((ss1[1][2] > 'C' and ss2[1][2] > 'C') or (ss1[1][2] <= 'C' and ss2[1][2] <= 'C'))
	{
		cout << "111";
		if (abs(ss1[1][2]-ss2[1][2]) == 1)
			cout << "1\n";
		else
			cout << "0\n";
		return 0;	
	}
	cout << "1100\n";
	return 0;
}
