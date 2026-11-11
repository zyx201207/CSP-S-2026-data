#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, l, r) for(int i = l; i <= r; i++)
int n, m, a[500005], s[500005], ans;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	rep(i, 1, n) s[i] = s[i - 1] + a[i];
	int l = 1;
	rep(i, 1, n) {
		while(l < i && (i - l + 1) * a[i] - s[i] + s[l - 1] > m) l++;
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}
