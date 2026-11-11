#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5;

int c, t, n, d, x[N];
int dis[N], sel[N], ans;

deque<int> q;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> t;
	while(t--) {
		ans = 0;

		cin >> n >> d;
		for(int i = 1; i <= n; i++) {
			cin >> x[i];
		}

		if (c <= 10) {
			for(int i = 1; i <= n; i++) {
				dis[i] = 0; sel[i] = 1; sel[i - 1] = 0;
				q.push_back(i);

				for(int j = i + 1; j <= n; j++) {
					if (x[j] - x[j - 1] > d) {
						break;
					}

					int l = lower_bound(x + i, x + j, x[j] - d) - x
					  , r = upper_bound(dis + i, dis + j, dis[l]) - dis - 1;
					dis[j] = dis[l] + 1;
					sel[j] = sel[r] - sel[l - 1];

					if (sel[j] == 2) {
						++ans;
					}

					sel[j] += sel[j - 1];
				}
			}

			cout << ans << "\n";
		} else {
			cout << "0\n";
		}
	}

	return 0;
}