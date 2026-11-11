#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], s[500005], ans = 1, sum;
bool f;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int y = a[2] - a[1];
	for (int i = 3; i <= n; i++) {
		if (a[i] - a[i - 1] != y) {
			f = 1;
			break;
		}
	}
	sort(a + 1, a + n + 1);
	if (f) {
		for (int i = 2; i <= n; i++)
			s[i] = (a[i] - a[i - 1]) * (i - 1) + s[i - 1];
	}
	for (long long i = 2; i <= n; i++) {
		long long x = 0;
		sum = s[i];
		if (!f && sum > m)
			break;
		while (sum > m) {
			x++;
			sum -= (a[i] - a[x]);
		}
		ans = max(ans, i - x);
	}
	cout << ans << endl;
	return 0;
}
