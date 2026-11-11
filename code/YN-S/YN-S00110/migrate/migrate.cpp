#include <bits/stdc++.h>
using namespace std;
int c, t, n, s[2000005], w[2000005], su[2000005];
long long a[2000005], d;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--) {
		int it = 1;
		long long ans = 0;
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			su[i] = 0;
			s[i] = 0;
			w[i] = 0;
			scanf("%lld", &a[i]);
		}
		if (n <= 3) {
			cout << 0 << '\n';
			continue;
		}
		for (int i = 2; i <= n; i++) {
			if (a[i] - a[it] > d)
				s[it] = i - it - 1, it++;
		}
		if(it==1) cout<<0<<'\n';
		if (a[n] - a[it] <= d) {
			s[it] = n - it;
		}
		for (int i = it + 1; i <= n; i++) {
			s[i] = n - i;
		}
		for (int i = 1; i <= n; i++) {
			w[i + 1] += 1, w[i + s[i] + 1] -= 1;
		}
		for (int i = 1; i <= n; i++) {
			su[i] = su[i - 1] + w[i];
		}
		for (int i = 4; i <= n; i++) {
			if (su[i] == 2)
				ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}