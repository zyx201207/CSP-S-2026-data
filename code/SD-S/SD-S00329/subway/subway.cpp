#include <bits/stdc++.h>

using namespace std;
int c, n, m, d, q; 
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	while (q--) {
		cout << d - n + m << '\n';
	}
	return 0;
}

