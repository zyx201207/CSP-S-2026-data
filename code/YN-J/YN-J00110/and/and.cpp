#include <bits/stdc++.h>
using namespace std;
long long a, n, m, ans = 0, mx = -1;
bool b[50];

struct S {
	long long x, d[100], l;
} q[200005];

bool cmp(S x, S y) {
	if (x.x != y.x)
		return x.x > y.x;
	return x.l > y.l;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	memset(b, 1, sizeof(b));

	for (int i = 1; i <= n; i++) {

		cin >> a;
		int tot = 1;

		while (a > 0) {
			q[i].d[tot] = a % 2;

			if (a % 2 == 1)
				q[i].x++;
			q[i].l++;
			tot++;
			a /= 2;
		}

		mx = max(mx, q[i].l);
	}

	sort(q + 1, q + n + 1, cmp);

	for (int i = 2; i <= m; i++)

		for (int j = 1; j <= q[i].l; j++)

			if (!(q[i].d[j] == 1 && q[i - 1].d[j] == 1))
				b[j] = 0;

	for (int i = 1; i <= mx; i++)

		if (b[i]) {
			long long tot = 1;

			for (int j = 1; j < i; j++)

				tot *= 2;
			ans += tot;
		}


	cout << ans;
	return 0;
}
