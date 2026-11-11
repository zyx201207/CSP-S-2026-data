#include <bits/stdc++.h>

using namespace std;

bool nex[500][500];

int main()
{
	freopen("travel.in", "r", stdin), freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	nex['A']['B'] = nex['B']['A'] = true,
	nex['B']['C'] = nex['C']['B'] = true,
	nex['D']['F'] = nex['F']['D'] = true;
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 == c2)
	{
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[1])
		{
			cout << "1";
			if
			(
				(s1[2] <= 'C' && s2[2] <= 'C') ||
				('D' <= s1[2] && 'D' <= s2[2])
			)
			{
				cout << "1";
				if (nex[s1[2]][s2[2]]) cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
