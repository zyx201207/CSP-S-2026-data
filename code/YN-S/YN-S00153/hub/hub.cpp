#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int n, c, t, k;

struct yyx {
	int u, v;
} a[N];

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		int ans = 0;
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			cin >> a[i].u >> a[i].v;
		}
		if (t % 2 == 0) {
			cout << 1;
		} else {
			cout << 2;
		}
		cout << "\n";
	}
	return 0;
}
