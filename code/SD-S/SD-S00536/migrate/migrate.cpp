// 24 pts.
// c \in [1, 6].
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5003;

int c, t, n;
ll maxd, x[MAXN], ans;
int minl[MAXN], way[MAXN];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> t;
	if (1 <= c && c <= 10) {
		while (t--) {
			ans = 0;
			cin >> n >> maxd;
			for (int i = 1; i <= n; i++) {
				cin >> x[i];
			}
			for (int st = 1; st <= n; st++) {
				minl[st] = 0;
				memset(way, 0, sizeof way);
				way[st] = 1;
				for (int ed = st + 1; ed <= n; ed++) {
					int pos = lower_bound(x + st, x + n + 1, x[ed] - maxd) - x;
					minl[ed] = minl[pos] + 1;
					for (int k = pos; k < ed && minl[k] == minl[pos]; k++) {
						if (way[k] == -1 || way[k] > 2 || way[k] + way[ed] > 2) {
							way[ed] = -1;
							break;
						}
						way[ed] += way[k]; 
					}
					if (way[ed] == 2) {
						ans++;
					}
				}
			}
			cout << ans << "\n";
		}
		return 0;
	}
	return 0;
}
/*
1 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
