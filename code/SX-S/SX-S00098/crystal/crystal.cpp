#include <bits/stdc++.h>
using namespace std;

long long n, m, a[500005], x[500005] = {0}, ans = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		x[i] = x[i - 1] + a[i];
	for (long long i = 1; i <= n; i++) {
		if (i * a[i] - x[i] <= m)
			ans = i;
		if (ans != i) {
			long long j = i + 1;
			while (i * a[j] - x[j] + x[j - i] > m && j <= n)
				j++;
			if (j <= n) {
				ans = i;
			}
		}
		if (ans != i)
			break;
	}
	cout << ans;
	return 0;
}