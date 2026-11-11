#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 500005;

int n, ans;
ll m, val[MAXN], pre[MAXN];

ll need(int l, int r) {
	return val[r] * (r - l + 1) - (pre[r] - pre[l - 1]);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> val[i];
	}
	sort(val + 1, val + n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + val[i];
	}
	for (int l = 1, r = 1; r <= n;) {
		if (need(l, r) <= m) {
			ans = max(ans, r - l + 1);
			r++;
		} else {
			while (l < r && need(l, r) > m) {
				l++;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}

