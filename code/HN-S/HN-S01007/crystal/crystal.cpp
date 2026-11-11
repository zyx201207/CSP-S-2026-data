#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 500000 + 7;

int n, m, a[N], dis[N], d[N], pre[N];

bool check(int mid) {
	int res = 0;
	for (int i = 1; i <= n; i++) res += max(0LL, mid - a[i]);
	return res <= mid;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]); 
	sort(a + 1, a + n + 1);
	// int ans = 0;
	// for (auto i : mp) ans = max(ans, i.second);
	// for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
	// for (int i = 2; i <= n; i++) printf("%lld\n", (i - 1) * (a[i] - a[i - 1]));
	int sum = 0, ans = 0, res = 0;
	for (int l = 1, r = 1; l <= n; ) {
		for (; r <= n && sum <= m; r++) sum = a[r] * (r - l) - res, res += a[r];
		ans = max(ans, r - l);
		res -= a[l];
		++l;
		sum = a[r] * (r - l) - res; 
	}
	printf("%lld\n", ans - 1);
	return 0;
}


// g++ crystal.cpp -o crystal -g -O2 -std=c++14 -static
// ./crystal
// time ./crystal