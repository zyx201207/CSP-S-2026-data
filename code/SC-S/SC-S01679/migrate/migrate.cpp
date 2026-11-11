#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX / 2;

int c, t;
int n;
long long d;
long long x[305];
pair<int, int> dis[305][305];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (cin >> c >> t; t--; ) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		long long res = 0;
		for (int i = 1; i <= n; i++) {
			dis[i][i] = {0, 1};
			for (int j = i + 1; j <= n; j++) {
				dis[i][j] = {INF, 0};
				for (int k = j - 1; k >= i && x[j] - x[k] <= d; k--) {
					if (dis[i][j].first > dis[i][k].first + 1)
						dis[i][j] = {dis[i][k].first + 1, dis[i][k].second};
					else if (dis[i][j].first == dis[i][k].first + 1)
						dis[i][j].second += dis[i][k].second;
				}
				dis[i][j].second = min(dis[i][j].second, 3);
				if (dis[i][j].second == 2)
					res++;
			}
		}
		cout << res << '\n';
	}
	return 0;
}