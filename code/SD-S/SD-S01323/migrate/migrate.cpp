#include <iostream>
#include <algorithm>
using namespace std;

int c, t;
int n;
long long d;
long long x[5001];

int ans;

int dis[5001][5001];

int dis1(int a, int b) {
	if (dis[a][b] > 0 && dis[a][b] < 0x3f3f3f3f) {
		return dis[a][b];
	}
	if (x[b] - x[a] <= d) {
		return dis[a][b] = 1;
	}
	
	int minn = 0x3f3f3f3f;
	for (int i = a + 1; i < b; ++i) {
		minn = min(dis1(a, i) + dis1(i, b), minn);
	}

	return dis[a][b] = minn;
}

void dis2(int a, int b) {
	int res = 0;
	if (x[b] - x[a] <= d) {
		return;
	}
	for (int i = a + 1; i < b; ++i) {
		if (dis[a][i] + dis[i][b] == dis[a][b]) {
			++res;
		}
	}
	if (res == 2) {
		++ans;
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> c >> t;
	while (t--) {
		ans = 0;
		
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
		}
		
		dis1(1, n);
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				dis2(i, j);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
