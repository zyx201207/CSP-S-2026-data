#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
ll a[N], m, c, n;
int maxx = 0, l = 1, cnt = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];

	}

	sort(a + 1, a + 1 + n);


	for (int i = 1; i <= n; i++) {

		c = 0, maxx = 0;

		for (int j = l; j <= i; j++) {

			c += a[i] - a[j];

			if (c <= m) {
				maxx++;
				cnt = max(maxx, cnt);
			} else
				while (c > m) {
					maxx--;
					c -= a[i] - a[l];
					l++;
				}
		}
	}

	cout << cnt;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
10 11
1 2 7 8 9 10 11 20 23 24
*/
