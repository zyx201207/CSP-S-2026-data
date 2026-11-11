#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 500005

long long n, m;
long long a[N], s[N];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i, res = i;
		while (l <= r) {
			int mid = l+r>>1;
			if (a[i]*(i-mid) - s[i-1] + s[mid-1] <= m) r = mid-1, res = mid;
			else l = mid+1;
		}
		ans = max(ans, i-res+1);
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int T = 1;
	// cin >> T;
	while (T--) solve();
	return 0;
}
