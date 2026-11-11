#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL maxn = 5e5 + 5;
LL n, m, a[maxn], sum[maxn], ans = 0;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (LL i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (LL i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for (LL l = 1, r = 1; r <= n; r++) {
		while ((r - l) * a[r] - (sum[r - 1] - sum[l - 1]) > m)
			l++;
		ans = max(ans, r - l + 1);
	}
	cout << ans << '\n';
	return 0;
}