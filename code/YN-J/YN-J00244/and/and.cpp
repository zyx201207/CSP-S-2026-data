#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
long long n, m, a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	bool is_4 = true;
	long long res1 = -1e18, res2 = 0, res3 = -1e18;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 1)
			res2 = a[i];
		else
			res2 &= a[i];
		res1 = max(res1, (long long)a[i]);
		if (a[i] > 4)
			is_4 = false;
	}
	if (m == 1)
		cout << res1;
	else if (m == n)
		cout << res2;
	else if (m == 2) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i != j)
					res3 = max(res3, a[i] & a[j]);
		cout << res3;
	} else if (is_4) {
		int cnt1 = count(a + 1, a + n + 1, 1);
		if (cnt1 >= m)
			cout << 1;
		else
			cout << 0;
	} else {
		sort(a + 1, a + n + 1);
		long long res = -1e18;
		do {
			long long now = a[1];
			for (int i = 2; i <= m; i++)
				now &= a[i];
			res = max(now, res);
		} while (next_permutation(a + 1, a + n + 1));
		cout << res;
	}
	return 0;
}