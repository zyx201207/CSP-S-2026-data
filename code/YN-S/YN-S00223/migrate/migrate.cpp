#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 305;
int c, t;
int n;
ll d, x[N], dis[N][N], cnt[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> t;

	while (t--) {
		cin >> n >> d;
		memset(dis, 0x3f3f3f3f, sizeof dis);

		for (int i = 1; i <= n; i++) {

			cin >> x[i];
		}

		for (int i = 1; i <= n; i++) {

			for (int j = i + 1; j <= n; j++) {

				if (j == i)
					continue;
				ll a = abs(x[i] - x[j]);

				if (a <= d) {
					dis[i][j] = 1;
					dis[j][i] = 1;
				}
			}
		}



		for (int k = 1; k <= n; k++) {

			for (int i = 1; i <= n; i++) {

				for (int j = 1; j <= n; j++) {

					if (i == j || dis[i][k] == 0x3f3f3f3f || dis[k][j] == 0x3f3f3f3f)
						continue;
					ll a = dis[i][k] + dis[k][j];

					if (dis[i][j] == a) {
						cnt[i][j]++;
					}

					if (dis[i][j] > a) {
						cnt[i][j] = 0;
						dis[i][j] = a;
					}
				}
			}
		}

		int ans = 0;

		for (int i = 1; i <= n; i++) {

			for (int j = i + 1; j <= n; j++) {

				if (cnt[i][j] == 1)
					ans++;
			}

		}

		cout << ans << "\n";
	}

	return 0;
}
