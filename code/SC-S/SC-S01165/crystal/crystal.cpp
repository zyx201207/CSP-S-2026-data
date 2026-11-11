#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 500005
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x * f;
}
int n, m, a[maxn];
int sum[maxn], ans;
void solve() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), sum[i] = sum[i - 1] + a[i];
	sort(a + 1, a + n + 1);
	int tot = a[(n + 1) / 2];
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (tot * (j - i + 1) - sum[j] - sum[i - 1] == m)ans = max(ans, j - i + 1);
	printf("%lld", ans);
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	solve();
	return 0;
}