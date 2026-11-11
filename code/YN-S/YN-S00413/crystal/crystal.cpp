#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 5e5 + 7;
LL a[N], s[N];
LL n, m;
LL ans = -N;

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

	sort(a + 1, a + 1 + n);
	s[1] = 0;
	for (int i = 2; i <= n; i++) {
		s[i] = (a[i] - a[i - 1]) * (i - 1) + s[i - 1];
	}
	for (LL i = 1; i <= n; i++) {
		for (LL j = i; j <= n; j++) {
			if (s[j] - s[i] <= m) {
				ans = max(ans, j - i + 1);
			}
		}
	}
	cout << ans;
	return 0;
}