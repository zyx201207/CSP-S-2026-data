#include <bits/stdc++.h>
#define i64 long long
#define i32 int
#define rep(i, l, r) for (i64 i = l; i <= r; ++i)
#define per(i, r, l) for (i64 i = r; i >= l; --i)
using namespace std;
i64 calc(string s) {
	i64 x = 0;
	for (auto v : s) {
		x = x * 10 + v - '0';
	}
	return x;
}
i32 main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	i64 c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000\n";
		return 0;
	}
	c1 = calc(s1.substr(0, 1ll * s1.size() - 1));
	c2 = calc(s2.substr(0, 1ll * s2.size() - 1));
	if (c1 != c2) {
		cout << "1000\n";
		return 0;
	}
	char ch1 = s1[1ll * s1.size() - 1];
	char ch2 = s2[1ll * s2.size() - 1];
	if ((ch1 <= 'C') != (ch2 <= 'C')) {
		cout << "1100\n";
		return 0;
	}
	if (ch1 > ch2) swap(ch1, ch2);
	if (ch1 == 'D' && ch2 == 'F') {
		cout << "1111\n";
		return 0;
	}
	if (ch1 == 'A' && ch2 == 'B') {
		cout << "1111\n";
		return 0;
	}
	if (ch1 == 'B' && ch2 == 'C') {
		cout << "1111\n";
		return 0;
	}
	cout << "1110\n";
	return 0;
}
