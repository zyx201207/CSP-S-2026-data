#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5;

int c, _, n, d;
int pos[N], lft[N], rgt[N];

signed main () {
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	cin >> c >> _;
	while (_--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> pos[i];
		int tot = 0;
		for (int i = 3; i <= n; i++) {
			if (pos[i] - pos[i - 2] > d && 
				pos[i - 1] - pos[i - 2] <= d && pos[i] - pos[i - 1] <= d) tot++;
			else tot = 0;
			lft[i] = tot;
		}
		tot = 0;
		rgt[n] = rgt[n - 1] = 0;
		for (int i = n - 2; i > 0; i--) {
			if (pos[i + 2] - pos[i] > d && 
				pos[i + 2] - pos[i + 1] <= d && pos[i + 1] - pos[i] <= d) tot++;
			else tot = 0;
			rgt[i] = tot;
		}
		int ans = 0;
		for (int i = 1; i < n - 2; i++) {
			if (pos[i + 2] - pos[i] <= d && pos[i + 3] - pos[i + 1] <= d && 
				pos[i + 3] - pos[i] > d)
				ans += (lft[i + 1] + 1) * (rgt[i + 2] + 1);
		}
		cout << ans << "\n";
	}
	return 0;
}