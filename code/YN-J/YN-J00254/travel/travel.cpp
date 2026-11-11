#include <bits/stdc++.h>
#define int long long
using namespace std;
string c1, s1, c2, s2, t1, t2;

bool same_side(char x, char y) {
	return ('A' <= x && x <= 'C' && 'A' <= y && y <= 'C') || ('D' <= x && x <= 'F' && 'D' <= y && y <= 'F');
}

bool is_next(char x, char y) {
	if (x == 'A')
		return (y == 'B');
	if (x == 'B')
		return (y == 'A') || (y == 'C');
	if (x == 'C')
		return (y == 'B');
	if (x == 'D')
		return (y == 'F');
	if (x == 'F')
		return (y == 'D');
	return false;
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	t1.push_back(s1[0]), t1.push_back(s1[1]);
	t2.push_back(s2[0]), t2.push_back(s2[1]);
	bool f1 = (c1 == c2), f2 = (f1 && t1 == t2);
	bool f3 = (f2 && same_side(s1.back(), s2.back())), f4 = (f3 && is_next(s1.back(), s2.back()));
	cout << f1 << f2 << f3 << f4 << '\n';
	return 0;
}