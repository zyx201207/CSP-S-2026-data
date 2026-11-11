#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 10, xx = 1e12;
long long n, m, ans, a[N], cntx;
bool check(long long x) {
	long long cnt = 0;
	for (int i = 1; i <= n; i++) if (a[i] < x) cnt += (x - a[i]);
	return cnt <= m;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	long long l = -xx, r = xx;
	while (l <= r) {
		long long mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1, cntx = mid;
		else r = mid - 1;
	}
	for (int i = 1; i <= n; i++) if (a[i] <= cntx) ans++;
	cout << ans;
	return 0;
}