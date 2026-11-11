#include <bits/stdc++.h>
using namespace std;

long long n, m, ans = -0x3f3f, a[500005], b[500005];
bool f = 1;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i)
			f = 0;
	}
	if (f == 1) {
		cout << int((sqrt(8 * m + 1) - 1) / 2) + 1;
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		long long s = 0, t = m, j = i;
		while (t >= a[i] - a[j] and j >= 1) {
			s++;
			t -= a[i] - a[j];
			j--;
		}
		ans = ((ans > s) ? ans : s);
	}
	cout << ans;
	return 0;
}