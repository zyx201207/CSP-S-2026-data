#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int c, d, p, q, n, m;
string s, t;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin), freopen("travel.out", "w", stdout);
	cin >> c >> s >> d >> t;
	p = (s[0] - '0') * 10 + s[1] - '0', q = (t[0] - '0') * 10 + t[1] - '0';
	m = s[2] - 'A', n = t[2] - 'A';
	cout << (c == d) << (c == d && p == q) << (c == d && p == q && ((m <= 2 && n <= 2) || (m >= 3 && n >= 3)));
	cout << (c == d && p == q && ((m <= 2 && n <= 2) || (m >= 3 && n >= 3)) && abs(m - n) == 1);
	return 0;
}
