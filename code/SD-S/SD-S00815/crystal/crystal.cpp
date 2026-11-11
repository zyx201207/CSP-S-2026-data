#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int n;
ll m;
ll a[500050], d[500050], sumd[500050];
ll ans, cnt, lst = 1;
ll maxcnt = -1;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; ++i)
		d[i] = a[i] - a[i - 1];
	for (int i = 2; i <= n; ++i)
		sumd[i] = sumd[i - 1] + d[i];
	for (int i = 2; i <= n; ++i) {
		ans += d[i] * (++cnt);
		while (ans > m) ans -= (sumd[i] - sumd[lst - 1]), ++lst, --cnt;
		maxcnt = max(maxcnt, cnt);
	}
	cout << maxcnt + 1;
	return 0;
}
