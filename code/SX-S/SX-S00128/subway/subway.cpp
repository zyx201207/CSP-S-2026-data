#include <bits/stdc++.h>
using namespace std;
#define int long long
int w[600000];

struct NN {
	int tar, d;
	NN(int a, int b) {
		tar = a, d = b;
	}
};
vector<NN> rail[502];
vector<NN> station[500006];
set<int> save;
int dis[1009][1009];
int cpy[1009];
int dp[1009][1009];
int inde[600009][2];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int x = 1; x <= m; x++) {
		cin >> w[x];
	}
	for (int x = 0; x < n; x++) {//第x条线
		int k;
		cin >> k;
		for (int y = 0; y < k; y++) {
			int a, b;
			cin >> a >> b;
			rail[x].push_back(NN(a, b)); //第x条线能通往站a的站厅，距离是b
			station[a].push_back(NN(x, b)); //a站有x线的火车站台,从站厅过去距离b
			save.insert(a);
		}
	}
	int ind = 0;
	for (auto x : save) {
		cpy[ind++] = x;
	}
	ind++;
	if (c >= 20 && c <= 21) {
		while (q--) {
			memset(inde, -1, sizeof(ind));
			int sx, sy, posx, posy;
			cin >> sx >> sy;
			int x1 = rail[0].size(), x2 = rail[1].size();
			for (int x = 0; x < x1; x++) {
				inde[rail[0][x].tar][0] = x;
			}
			for (int x = 0; x < x2; x++) {
				inde[rail[1][x].tar][1] = x;
			}
			if (inde[sx][0] != -1 && inde[sy][0] != -1) {
				cout << rail[0][inde[sx][0]].d + rail[0][inde[sy][0]].d + w[sx] + w[sy] << '\n';
			} else if (inde[sx][1] != -1 && inde[sy][1] != -1) {
				cout << rail[1][inde[sx][1]].d + rail[1][inde[sy][1]].d + w[sx] + w[sy] << '\n';
			} else {
				int minn = 2147483647;
				for (int x = 0; x < ind; x++) {
					if (inde[x][0] != -1 && inde[x][1] != -1) {
						minn = min(rail[0][inde[x][0]].d + rail[1][inde[x][1]].d, minn);
					}
				}
				if (inde[sx][0] != -1)
					cout << w[sx] + w[sy] + rail[0][inde[sx][0]].d + rail[1][inde[sy][1]].d + minn << '\n';
				else
					cout << w[sx] + w[sy] + rail[1][inde[sx][1]].d + rail[0][inde[sy][0]].d + minn << '\n';
			}
		}
		return 0;
	}

//	cout << ind++ << '\n';
//	system("pause");
	for (int x = 0; x < 1002; x++) {
		for (int y = 0; y < 1002; y++) {
			dis[x][y] = 2147483647;
		}
	}
//	cout << "have gotten out\n";
	for (auto x : save)
		for (auto rl : station[x]) {
			for (auto dstnt : rail[rl.tar]) {
				if (x == dstnt.tar)
					continue;
				//		cout << "from " << x << " stt,to " << dstnt.tar << " with rail " << rl.tar << '\n';
				dis[dstnt.tar][x] = dis[x][dstnt.tar] = min(dis[x][dstnt.tar], rl.d + dstnt.d);
			}
		}

	for (int x = 0; x < ind; x++) {
		for (int y = 0; y < ind; y++) {
			if (x == y)
				dp[x][y] = dp[y][x] = 0;
			else if (dis[x][y] != 2147483647) {
				//	cout << "able to move between " << y << " " << x << " with time " << dis[x][y] << '\n';
				dp[x][y] = dp[y][x] = dis[x][y];
			} else
				dp[x][y] = dp[y][x] = 2147483647;
		}
	}
	for (int mid = 0; mid < ind; mid++) {
		for (int x = 0; x < ind; x++) {
			for (int y = 0; y < ind; y++) {

				if (mid == x || mid == y)
					continue;
				if (dp[x][mid] != 0 && dp[mid][y] != 0) {
					dp[y][x] = dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid][y]);
				}
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		//	cout << (long long)dp[x][y] << '\n';
		cout << (long long)dp[x][y] + w[x] + w[y] << '\n';
	}
	return 0;
}