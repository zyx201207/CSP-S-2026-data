#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
ll a[N], b[N], sum[N];
int n;
ll m;
int ans, re;
void solve2() {
	for (int i = 1; i <= n; i++) {
		b[i] = a[i] - a[i - 1];
		sum[i] = sum[i - 1] + b[i];
	}
	int i = 2, j = 2;
	ll d = 0;
	for (; i <= n && j <= n; i++) {
		while (j <= n && b[j] * (j - i) + d <= m) d += b[j] * (j - i), j++;
		j--;
		while (j <= n && d - sum[j] + sum[i - 1] + b[j + 1] * (j - i))
			d += -sum[j] + sum[i - 1] + b[j + 1] * (j - i), i++, j++;
		ans = max(ans, j - i + 1);
	}
	// cout << i << " " << j << endl;
	cout << ans << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	solve2();

	return 0;
}