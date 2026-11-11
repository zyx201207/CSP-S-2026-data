#include<bits/stdc++.h>
#define int long long
#define inf 1e9
using namespace std;
int n, m, ans, s[500005], a[500005]; 
int find(int x) {
	int l = 1, r = x, ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (s[x] - s[mid - 1] >= a[x] * (x - mid + 1) - m) {
			ans = mid, r = mid - 1;
		} else {
			l = mid + 1;	
		}
	}
	return ans;
}
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		int p = find(i);
		if (!p) continue;
		ans = max(ans, i - p + 1);
	}
	cout << ans;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int T = 1;
	while (T--) solve();
	return 0;
}

