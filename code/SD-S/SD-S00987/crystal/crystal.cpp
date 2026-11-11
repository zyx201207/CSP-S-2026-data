#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],s[500010];
bool check(int x) {
	for (int i = x; i <= n; ++i) {
		int cnt = x * a[i] - (s[i] - s[i - x]);
		if (cnt <= m) return 1;
	}
	return 0;
}
signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1,a + 1 + n);
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
	int l = 1,r = n,ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) ans = mid,l = mid + 1;
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}

