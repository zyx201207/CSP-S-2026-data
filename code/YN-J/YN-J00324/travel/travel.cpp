#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	bool t1 = (c1 == c2);
	bool t2 = (t1 && (s1.substr(0, 2) == s2.substr(0, 2)));
	bool t3 = (t2 && (('A' <= s1[2] && s1[2] <= 'C' && 'A' <= s2[2] && s2[2] <= 'C') || ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'))));
	bool t4 = (t3 && (('A' <= s1[2] && s1[2] <= 'C' && 'A' <= s2[2] && s2[2] <= 'C' && abs(s1[2] - s2[2]) == 1) || ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'))));
	cout << t1 << t2 << t3 << t4;
	return 0;
}