/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2026-10-31 08:22
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;
long long n, m, cnt[200005], a[200005], s[200005], p = 1, ap = 1, x;
bool f;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> s[i];
	}

	for (int g = 1; g <= n; g++) {

		for (int i = g; i <= n; i++) {

			for (int j = 1; j <= ap; j++) {

				if (a[j] == s[i]) {
					f = 1;
					x = j;
					break;
				}
			}

			if (f) {
				f = 0;

				for (int h = x; h <= ap - 1; h++) {


					a[h] = 0;

				}


				a[x] = s[i];
				ap = x + 1;
			} else {
				a[ap] = s[i];

				ap++;
			}
		}

		for (int i = 1; i <= ap; i++) {

			cnt[a[i]]++;
			a[i] = 0;
		}

	}

	for (int i = 1; i <= m; i++) {

		cout << cnt[i] << " ";
	}

	return 0;
}

