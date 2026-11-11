#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e5 + 8;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n, m, a[MAXN], b[MAXN], c[MAXN], ans = 0, w = 0, k = INF, s;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	bool dc = true;
	int o;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];

		if (i == 2) {
			o = a[2] - a[1];
		}

		if (i > 2 && a[i] - a[i - 1] != o) {
			dc = false;
		}
	}

	if (dc) {
		cout << min(n, m / o + 1) << " ";
		//cout << o << endl;
		return 0;
	}

	sort(a + 1, a + n + 1);

	w = m;

	for (int i = n, s; i >= 1; i--) {

		if (i == n) {
			s = 1;
			int j = i - 1, l = 0;

			for (; j >= 1; j--) {

				l = a[i] - a[j];
				//cout << i << " " << j << " ";

				if (w < l) {
					break;
				} else {
					w -= l;
					s++;

					if (j == 1) {
						cout << max(s, ans);
						return 0;
					}
				}
			}
		} else {
			w += (a[i + 1] - a[i]) * (s - 1);
			int j = i + 1 - s;
			s--;
			int l = 0;

			for (; j >= 1; j--) {

				l = a[i] - a[j];

				if (w < l) {
					break;
				} else {
					w -= l;
					s++;

					if (j == 1) {
						cout << max(s, ans);
						return 0;
					}
				}
			}
		}

		ans = max(ans, s);
		//cout << ans << endl;
	}

	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/