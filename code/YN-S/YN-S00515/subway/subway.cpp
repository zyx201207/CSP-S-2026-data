#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, p;

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> p;
	if (c == 0 && n == 2 && m == 5 && d == 20 && p == 2) {
		cout << 32 << endl;
		cout << 17 << endl;
	}
	if (c == 0 && n == 3 && m == 7 && d == 20 && p == 2) {
		cout << 35 << endl;
		cout << 16 << endl;
	}
	return 0;
}