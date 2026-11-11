#include <bits/stdc++.h>

using namespace std;

const int N = 500009;

long long n, a[N], s[N], t[N], m;
long long ans = 0, l=0;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n; ++ i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int r = 2; r <= n;  ++ r) {
		s[r] = s[r - 1] + (a[r] - a[r - 1]) * (r - 1);
		int tmp = s[r] - s[l] - l * (a[r] - a[l]);
		while (tmp > m) {
			ans = max(ans, r-l-1);
			l ++;
			tmp = s[r] - s[l] - l * (a[r] - a[l]);
		}
	}
	if (l == 0) cout << n << endl;
	else cout << ans << endl;
	return 0;
}
