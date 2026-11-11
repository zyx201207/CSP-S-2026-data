#include <bits/stdc++.h>
using namespace std;
int n, d;
int c, t;
int a[10000005];

bool check(int u, int v, int y) {
	int cnt = v - u;
	if (cnt != y)
		return 0;
	else
		return 1;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t) {
		cin >> n >> d;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (check(i, j, d)) {
					ans ++;
				}
			}
		}
		cout << ans << endl;
		t--;
	}
	return 0;
}/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

 0 2
 5 3
-2 -10 1 2
 6 2
-4 -3 -2 -1 3 6

*/

