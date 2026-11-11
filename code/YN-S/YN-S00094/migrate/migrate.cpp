#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	scanf("%d %d", &c, &t);

	while (t--) {
		int n;
		ll d;
		scanf("%d %lld", &n, &d);

		vector<ll> x(n + 1);
		for (int i = 1; i <= n; ++i)
			scanf("%lld", &x[i]);

		if (n < 3) {
			puts("0");
			continue;
		}
		vector<int> R(n + 1);
		int j = 1;
		for (int i = 1; i <= n; ++i) {
			if (j < i)
				j = i;
			while (j + 1 <= n && x[j + 1] - x[i] <= d)
				++j;
			R[i] = j;
		}
		vector<char> isDiv(n + 1, 0);
		for (int i = 1; i <= n; ++i)
			if (R[i] >= i + 2)
				isDiv[i] = 1;
		vector<char> isRDiv(n + 1, 0);
		for (int i = 3; i <= n; ++i)
			if (x[i] - x[i - 2] <= d)
				isRDiv[i] = 1;
		vector<int> last(n + 1, 0);
		int lastDiv = 0;
		for (int i = 1; i <= n; ++i) {
			last[i] = lastDiv;
			if (isDiv[i])
				lastDiv = i;
		}

		vector<int> nxt(n + 1, n + 1);
		int nxtDiv = n + 1;
		for (int i = n; i >= 1; --i) {
			nxt[i] = nxtDiv;
			if (isRDiv[i])
				nxtDiv = i;
		}
		vector<ll> preW(n + 2, 0);
		for (int i = 1; i <= n; ++i) {
			ll w = nxt[i] - i;
			preW[i] = preW[i - 1] + w;
		}

		ll ans = 0;

		for (int a = 1; a <= n; ++a) {
			if (!isDiv[a])
				continue;

			int ra = R[a];
			int ra2 = ra - 2;
			int L = max(ra, R[ra2]);
			int U = R[ra - 1];

			if (L < U) {
				ll sumW = preW[U] - preW[L];
				int cntPrefix = a - last[a];
				ans += 1LL * cntPrefix * sumW;
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}
