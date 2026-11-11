#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, cnt;
ll a[500005], s[500005];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) s[i] = a[i] - a[i - 1];
	for (int i = 1; i <= n; i++) {
		if (m < s[i]) break;
		m -= s[i];
		if (s[i] != 0) ++cnt;
	}
	cout << cnt;
	return 0;
}