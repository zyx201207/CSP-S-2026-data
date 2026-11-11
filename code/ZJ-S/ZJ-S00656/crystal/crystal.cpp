#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
#define int long long
int n, m, a[N], s[N];
inline int tryans(int x) {
	int pos = n + 1, pl = 1, pr = n;
	while(pl <= pr) {
		int mid = (pl + pr) >> 1;
		if(a[mid] > x) pos = mid, pr = mid - 1;
		else pl = mid + 1;
	}
	--pos;
	int ans = pos - 1;
	pl = 0, pr = pos - 1;
	while(pl <= pr) {
		int mid = (pl + pr) >> 1;
		if(x * (pos - mid) - (s[pos] - s[mid]) <= m) ans = mid, pr = mid - 1;
		else pl = mid + 1;
	}
	return pos - ans;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
	int res = 0;
	for(int i = 1; i <= n; ++i)
		res = max(res, tryans(a[i]));
	cout << res;
	return 0;
}