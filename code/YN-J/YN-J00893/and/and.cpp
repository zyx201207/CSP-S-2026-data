/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2026-10-31 08:22
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], maxn = -1, c, vis[200005];

bool cmp(int x, int y) {
	if (x > y) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	if (m == 2) {

		for (int i = 1; i <= n; i++) {

			for (int j = i + 1; j <= n; j++) {

				maxn = max(maxn, (a[i] & a[j]));
			}
		}

		cout << maxn;
	}

	else if (m == n) {
		c = a[1];

		for (int i = 2; i <= n; i++) {

			c = (c & a[i]);
		}

		cout << c;
	}

	else if (m == 1) {
		for (int i = 1; i <= n; i++) {

			maxn = max(maxn, a[i]);
		}

		cout << maxn;
	} else {
		sort(a + 1, a + n + 1, cmp);
		c = a[1];

		for (int i = 1; i <= m; i++) {

			c = (c & a[i]);
		}

		cout << c;
	}


	return 0;
}

