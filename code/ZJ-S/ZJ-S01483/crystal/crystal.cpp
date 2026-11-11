#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[500100];
signed main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf ("%lld %lld", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf ("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
	int t = 1, ma = 1;
	for (int w = 1; w <= n; ++w) {
		while((w - t + 1) * (a[w] - a[w - 1]) - (a[w] - a[t - 1]) > m) ++t;
//		cout << t << " " << w << endl;
		ma = max(ma, w - t + 1);
	}
	printf("%lld", ma);
	return 0;
}
