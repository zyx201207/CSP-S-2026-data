// c - j - c 2026 10 31 csp T1
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, m, a[N], s[N];

int main(void) {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i, ic = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if ((i - mid + 1LL) * a[i] <= s[i] - s[mid - 1] + m)
				r = mid - 1, ic = mid;
			else
				l = mid + 1;
		}
		res = max(res, (i - ic + 1LL));
	}
	cout << res;
	return 0;
}