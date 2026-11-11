#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m;
int a[N];

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int sum = a[1], id = 1, ans = 0;
	while (true) {
		ans++;
		if (id == n) {
			cout << n;
			return 0;
		}
		int num = a[id + 1] * id - sum * id;
		if (num < 0)
			num *= -1;
		if (m >= num) {
			m -= num;
			sum = a[id + 1];
		} else
			break;
		id++;
	}
	cout << ans;
	return 0;
}