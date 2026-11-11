#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
long long n, m, f[N], ans[M], b[N], cnt, cc;

struct node {
	long long m, id;
} a[N];

long long find(long long x) {
	for (long long i = 1; i < cnt; i++)

		if (a[i].m == x)
			return a[i].id;
}

bool check(long long x) {
	for (long long i = 1; i <= cnt; i++)

		if (f[i] == x)
			return 1;
	return 0;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;

	for (long long i = 1; i <= n; i++) {

		cin >> a[i].m;
		a[i].id = i;
	}

	cc = 0;

	while (n--) {
		cnt = 0;
		memset(b, 0, sizeof(b));
		memset(f, 0, sizeof(f));

		for (long long i = ++cc; i <= n; i++) {

			++cnt;

			if (i == cc) {
				f[cnt] = a[i].m;
				b[a[i].m]++;
			} else if (b[a[i].m] == 0) {
				f[cnt] = a[i].m;
				b[a[i].m]++;
			} else {
				b[a[i].m] = 1;
				cnt = find(a[i].m);
				f[cnt] = a[i].m;
			}
		}

		for (long long i = 1; i <= m; i++)

			if (check(i))
				ans[i]++;
	}

	for (long long i = 1; i <= m; i++)

		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}
