#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 5e5+10;
ll n, m, a[N], ans, mid, f;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		mid += a[i] - a[i - 1];
		mid += ans * (a[i] - a[i - 1]);
		ans++;
		if (mid <= m) {
			//ans++;
		} else {
			while (ans > 0) {
				mid += (a[i] - a[n - ans]);
				ans--;
				if (mid >= m) {
					break;
				}
			}
		}
		f = max(f, ans + 1);
	}
	cout << f;
	return 0;
}
