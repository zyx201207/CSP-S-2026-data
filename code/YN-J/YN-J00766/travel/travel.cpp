#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string c1, s1, c2, s2;
	int f = 1;
	cin >> c1 >> s1 >> c2 >> s2;
	int a1 = (c1 == c2);
	cout << a1;
	if (!a1)
		f = 0;
	//
	string p1, p2;
	for (int i = 0; i <= 1; i++) {
		p1 += s1[i];
		p2 += s2[i];
	}
	int a2 = (f && p1 == p2);
	cout << a2;
	if (!a2)
		f = 0;
	//
	int flag = 0;
	int x = s1[2], y = s2[2];
	if ('A' <= x && 'C' >= x && 'A' <= y && 'C' >= y )
		flag = 1;
	if (x == 'D' && y == 'F')
		flag = 1;
	if (x == 'F' && y == 'D')
		flag = 1;
	flag = (f && flag);
	cout << flag;
	if (!flag)
		f = 0;
	//
	int ans = 0;
	if (a1 != a2 || a1 != flag)
		ans = 0;
	else {
		if ('A' <= x && 'C' >= x && abs(x - y) == 1)
			ans = 1;
		if ('A' <= y && 'C' >= y && abs(x - y) == 1)
			ans = 1;
		if (x == 'D' && y == 'F')
			ans = 1;
		if (x == 'F' && y == 'D')
			ans = 1;
	}
	ans = (f && ans);
	cout << ans;
	return 0;
}