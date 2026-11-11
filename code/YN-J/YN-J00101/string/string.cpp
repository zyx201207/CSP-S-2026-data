#include <bits/stdc++.h>
using namespace std;
int t, q, r, l;
const int N = 2e5 + 10;
long long ct, a[N], x, y;
char c[N];

/*void dfs(int x){
	if()
}*/

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> t;

	for (int i = 1; i <= t; i++) {

		cin >> a[i] >> c[i];
		ct += a[i];
	}

	cout << ct << "\n";

	for (int i = 1; i <= t; i++) {

		x += a[i];

		if (x >= ct / 2) {
			q = i;
			break;
		}
	}

	//cout << x << "\n";
	y = ct * 1.0 / 2;
	l = 1;
	r = t;

	if (a[q] > (x - y) * 2)
		ct -= (x - y) * 2, a[q] -= (x - y) * 2;
	else
		ct = ct - (a[q] - (x - y)) * 2, a[q] -= (a[q] - (x - y)) * 2;

	//cout << ct << "\n";
	while (l < r) {
		if (c[l] == c[r]) {
			long long k = min(a[l], a[r]);
			ct -= k * 2;

			if (a[l] == k)
				l++, a[r] -= k;
			else
				r--, a[l] -= k;
		} else {
			long long k = min(a[l], a[r]);

			if (a[l] == k)
				l++, a[r] -= k;

			else
				r--, a[l] -= k;
		}
	}

	//cout << ct << "\n";

	if (ct % 2 == 1)
		cout << ct / 2 + 1;
	else
		cout << ct / 2;
	return 0;
}/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/