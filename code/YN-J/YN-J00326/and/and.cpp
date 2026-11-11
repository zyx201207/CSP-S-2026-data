#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m, a[N];
int tot = 0;
int ans = 0;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	tot = n;
	for (int j = 30; j >= 0; j--) {
		int cnt = 0;
		for (int i = 1; i <= tot; i++) {
			if ((a[i] & (1 << j)))
				cnt++;
		}
		int hk = 0;
		if (cnt >= m) {
			ans += (1 << j);
			for (int i = 1; i <= tot; i++) {
				if ((a[i] & (1 << j)))
					a[++hk] = a[i];
			}
			tot = hk;
		}

	}
	cout << ans;
	return 0;
}
