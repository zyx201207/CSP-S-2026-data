#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, ans, v = 0x3f3f3f3f;
int a[N], d[N];


int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int sum = 0;
	for (int i = 1; i < n; i++)
		sum += a[n] - a[i];
	if (m >= sum) {
		cout << n;
		return 0;
	}
	for (int x = 1; x <= n; x++) {
		int cnt = 0, m1 = m;
		for (int i = 1; i <= n; i++)
			if (a[i] == a[x])
				cnt++;
		int f = 0, l = 1;
		while (m1 >= 0) {
			if (x - l == 0)
				break;
			f = abs(a[x] - a[x - l]);
			if (m - f < 0)
				break;
			m1 -= f;
			cnt++;
			l++;
		}
		ans = max(cnt, ans);
	}
	cout << ans;
	return 0;
}