//1.crystal
#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5;
int a[N], c[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, num = 0, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	int cnt;
	if (n % 2 == 0)
		cnt = a[(n + 1) / 2] / 2 + a[(n - 1) / 2] / 2;
	else
		cnt = a[(n + 1) / 2];
	for (int i = 1; i <= n; i++) {
		c[i] = cnt - a[i];
		if (c[i] < 0) {
			cout << ans << endl;
			return 0;
		}
		num += c[i];
		ans++;
	}
	return 0;
}
