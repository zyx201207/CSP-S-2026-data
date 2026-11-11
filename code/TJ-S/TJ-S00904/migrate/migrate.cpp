//
#include <iostream>

using namespace std;

typedef long long ll;

#define N 305

ll c, T, n, d, x[2000005], ans, p[N][N];
bool A;

void solve() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) p[i][j] = 1e9;
	ans = 0;
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i + l - 1 <= n; i++) {
			int j = i + l - 1;
			if (x[j] - x[i] <= d) p[i][j] = 1;
			else {
				for (int k = i + 1; k <= j - 1; k++)
					p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
			}
		}
	}
		
	cout << ans << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int i = 3; i <= n; i++) {
			if (x[i] - x[i - 1] != x[i - 1] - x[i - 2]) A = true;
		}
		if (!A) {
			ll p = d / (x[2] - x[1]);
			if (p <= 1) cout << 0 << '\n';
			else cout << max(0ll, n - 2 * p + 1) << '\n';
		} else solve();
	}
	return 0;
}

/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

-3 0 1 2 3 4

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326
555555555555555547 999999999999999989

*/
