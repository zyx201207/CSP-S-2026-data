#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string c1, s1, c2, s2;
	bool f1 = 0, f2 = 0, f3 = 0, f4 = 0;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		f1 = 1;
		if(s1[0] == s2[0] && s1[1] == s2[1])
		{
			f2 = 1;
			int tp1, tp2;
			if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') tp1 = 1;
			else tp1 = 2;
			if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') tp2 = 1;
			else tp2 = 2;
			if(tp1 == tp2)
			{
				f3 = 1;
				int t1 = s1[2], t2 = s2[2];
				if(abs(t1 - t2) == 1)
				{
					f4 = 1;
				}
			}
		}
	}
	cout << f1 << f2 << f3 << f4 << '\n';
	return 0;
}