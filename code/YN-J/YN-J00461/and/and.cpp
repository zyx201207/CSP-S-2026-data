#include <bits/stdc++.h>
using namespace std;
#define in cin
#define out cout
#define int long long
const int N = 2e5 + 5;
int b[N], n, a[N], k, m, ans;
signed main() {
	freopen("and.in", "r", stdin), freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false), in.tie(nullptr), out.tie(nullptr);
	in >> n >> k;
	for (int i = 1; i <= n; i++) in >> a[i];
	for (int bit = 31; bit >= 0; bit--) {
		m = 0;
		for (int i = 1; i <= n; i++) if (ans == (a[i] & ans)) b[++m] = a[i];
		int cnt = 0;
		for (int i = 1; i <= m; i++)
			if ((b[i] & (ans | (1ll << bit))) == (ans | (1ll << bit))) cnt++;
		if (cnt >= k) ans |= 1ll << bit;
	}
	out << ans;
	return 0;
}