#include <bits/stdc++.h>
using namespace std;
#define in cin
#define out cout
#define int long long
const int N = 5e5 + 5;
int n, m, a[N], sum[N];
bool check(int x) {
	for (int i = 1; i + x - 1 <= n; i++)
		if (a[i] * x - (sum[i + x - 1] - sum[i - 1]) <= m) return true;
	return false;
}
signed main() {
	freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), in.tie(nullptr), out.tie(nullptr);
	in >> n >> m;
	for (int i = 1; i <= n; i++) in >> a[i];
	sort(a + 1, a + n + 1, greater <int> ());
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int l = 1, r = n, ans = 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	out << ans;
	return 0;
}