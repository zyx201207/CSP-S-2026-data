#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6+5;
int c, t, n,  pos, pre[N], posts[N], prew[N], postsw[N];
ll a[N], m, ans;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;

	/*
	0 1
	10 3
	0 3 6 7 8 9 10 11 14 17

	9
	*/


	while (t--) {
		scanf("%d%lld", &n, &m);
		ans = 0;
		a[n + 1] = 4e18;
		a[0] = -4e18;
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]), prew[i] = 0, postsw[i] = 0;
		pos = 1;
		for (int i = 1; i <= n; i++) {
			while (pos < n && a[pos + 1] - a[i] <= m)
				pos++;
			pre[i] = pos;
		}
		pos = n;
		for (int i = n; i; i--) {
			while (pos > 1 && a[i] - a[pos - 1] <= m)
				pos--;
			if (!posts[pos])
				posts[pos] = i;
		}

		for (int i = 1; i < n ; i++) {
			int tmp = i;
			while (a[i + 2] - a[i] > m && i < n &&
			        a[i + 1] - a[i] <= m && a[i + 2] - a[i + 1] <= m)
				i++;
			prew[i] = i - tmp + 1;
		}
		for (int i = n; i > 1; i--) {
			int tmp = i;
			while (a[i] - a[i - 2] > m && i > 1 &&
			        a[i] - a[i - 1] <= m && a[i - 1] - a[i - 2] <= m)
				i--;
			postsw[i] = tmp - i + 1;
		}

		/*	for (int i = 1; i <= n; i++)
				cout << pre[i] << ' ';
			cout << '\n';
			for (int i = 1; i <= n; i++)
				cout << posts[i] << ' ';
			cout << "\n";
			for (int i = 1; i <= n; i++)
				cout << prew[i] << ' ';
			cout << '\n';
		for (int i = 1; i <= n; i++)
			cout << postsw[i] << ' ';
		cout << "\n";*/

		for (int i = 1; i <= n; i++)
			if (posts[pre[i] - 1])
				ans += (ll)postsw[pre[i] - 1] * max(prew[i], 1);
		printf("%lld\n", ans);
	}
	return 0;
}
