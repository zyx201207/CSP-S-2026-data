#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, ans, mx = -1, num;
int t[110000], md[110000];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		mx = max(mx, num);
		md[num] = i;
		t[num]++;
		if (i == n) {
			ans = num;
		}
	}
	if (mx == 2) {
		if (ans == 1) {
			cout << n << ' ' << t[2] + (n - md[2]) << '\n';
		} else {
			cout << t[1] + (n - md[1]) << ' ' << n << '\n';
		}
	} else {
		for (int i = 1; i <= m; i++) {
			t[i] += t[i - 1];
			cout << t[i] << ' ';
		}
	}

	return 0;
}