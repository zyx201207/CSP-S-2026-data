#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m;
int a[N];
void solve() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	int l = 1, sum = 0, ans = 1;
	for (int i = 2; i <= n; i++) {
		sum += (a[i] - a[i - 1]) * (i - l);
		while (sum > m) {
			sum -= a[i] - a[l];
			l++;
		}
		ans = max(ans, i - l + 1);
	}
	printf("%lld", ans);
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	solve();
	return 0;
}