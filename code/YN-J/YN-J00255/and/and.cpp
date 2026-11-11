#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, ans, a[200005];
bool vis[200005];

void DFS(ll pos, ll res) {
	if (pos == m) {
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				ll sum = res & a[i];
				ans = max(ans, sum);
			}
		}
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		ll sum = res & a[i];
		if (pos == 1)
			sum = a[i];
		vis[i] = 1, DFS(pos + 1, sum), vis[i] = 0;
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	ll zero = 0LL;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0)
			zero++;
		else
			break;
	}
	if (m + zero > n) {
		cout << 0 << endl;
		return 0;
	} else if (m + zero == n) {
		ll pos = upper_bound(a + 1, a + 1 + n, 0) - a;
		ans = a[pos];
		for (int i = pos + 1; i <= n; i++)
			ans = ans & a[i];
		cout << ans << endl;
		return 0;
	}
	if (m == 1)
		ans = a[n];
	else if (m == 2) {
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ll sum = a[i] & a[j];
				ans = max(sum, ans);
			}
		}
	} else if (m == n) {
		ans = a[1];
		for (int i = 2; i <= n; i++)
			ans = ans & a[i];
	} else
		DFS(1, 0);
	cout << ans << endl;
	return 0;
}