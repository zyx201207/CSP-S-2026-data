#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005], b[500005], q[500005], h, t;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	ll ans = 0, i = 2, len = 1, sum;
	q[++t] = a[1];
	while (ans + len * (a[i] - q[t]) <= m && i <= n)
		ans += len * (a[i] - q[t]), q[++t] = a[i], ++len, ++i;
	sum = len;
	for (; i <= n;) {
		while (ans + len * (a[i] - q[t]) > m && h < t)
			++h, len--, ans -= q[t] - q[h];
		ans += len * (a[i] - q[t]), q[++t] = a[i], ++len, ++i;
		sum = max(sum, len);
	}
	cout << sum;
	return 0;
}
