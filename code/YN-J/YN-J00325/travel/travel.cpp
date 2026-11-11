#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("travel.in", "r", stdin);
	freopen("travle.out", "w", stdout);

	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 != c2)
	{
		cout << "0000" << '\n';
		return 0;
	}

	int tp = 0, tc = 0, xl = 0;
	if (s1[0] == s2[0] && s1[1] == s2[1])
	{
		tp = 1;
		if ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D'
		        && s2[2] <= 'F'))
		{
			tc = 1;
		}
		else
		{
			cout << "1100" << '\n';
			return 0;
		}

		if (abs(s1[2] - s2[2]) == 1)
		{
			xl = 1;
		}
		else if ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D'))
		{
			xl = 1;
		}
	}
	cout << "1" << tp << tc << xl << '\n';

	return 0;
}
