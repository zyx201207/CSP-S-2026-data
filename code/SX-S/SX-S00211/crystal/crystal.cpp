#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, a[100005], f = 0, sum = 0, mm, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	mm = m;
	for (int i = n - 1; i >= 1; i--) {
		sum = 0;
		m = mm;
		for (int j = i; j >= 1; j--) {
			if (a[j] + m >= a[n - f] || a[j] == a[n - f]) {
				m -= a[n - f] - a[j];
				sum++;
			} else
				break;
		}
		ans = max(sum, ans);
		f++;
	}
	cout << ans + 1;
	return 0;
}
