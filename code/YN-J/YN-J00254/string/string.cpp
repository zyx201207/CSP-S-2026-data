#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Maxn = 2e5 + 5;
int n, a[Maxn], len, ans;
char c[Maxn];

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i], len += a[i];
	int j = n;
	for (int i = 1; i <= n && j > i; i++) {
		int cnt = 0;
		while (j > i && cnt + a[j] <= a[i]) {
			cnt += a[j];
			ans += a[j] * (c[j] != c[i]);
			j--;
		}
		ans += (a[i] - cnt) * (c[j] != c[i]);
		a[j] -= (a[i] - cnt);
	}
	cout << ans << '\n';
	return 0;
}