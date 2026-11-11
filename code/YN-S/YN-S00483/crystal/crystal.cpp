#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5e5 + 50, M = 5e3;

ll a[N], b[M][M];

bool cmp(ll x, ll y) {
	return x > y;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	ll m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	ll ans = -0x3ffffffff;
	sort(a + 1, a + n + 1, cmp);

	for (int i = 1; i <= n; i++) {

		for (int j = i; j <= n; j++) {

			b[i][j] = a[i] - a[j];
		}

	}

	for (int i = 1; i <= n; i++) {

		ll  t = 0, cnt = 0, t1 = 0;

		for (int j = i; j <= n; j++) {

			if (b[i][j] == 0) {
				if (j != i) {
					t1++;
				}

				t++;
			}

			if (cnt + b[i][j] > m) {
				ans = max(ans, j - i + t - t1);
				break;
			}

			cnt += b[i][j];

			if (cnt == m) {

				ans = max(ans, j - i + t - t1);
				break;
			}
		}

	}

	cout << ans << "\n";
	return 0;
}


/*
6 20
1 3 4 8 13 17

5 6
1 7 7 7 103
*/
