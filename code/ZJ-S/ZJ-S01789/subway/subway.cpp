#include<bits/stdc++.h>
#define PII pair<int, int>
#define int long long
using namespace std;
const int N = 2e3 + 5;
int c, n, m, d, q, st, ed;
int w[N], a, t1;
int dis[N][N];
vector <PII> r[505];
int ans = 0;
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++){
			cin >> a >> t1;
			r[i].push_back({a, t1});
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			dis[i][j] = INT_MAX;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < r[i].size() - 1; j++) {
//			cout << r[i][j].first << " " << r[i][j + 1].first <<" " <<r[i][j].second + r[i][j + 1].second<< endl;
			dis[r[i][j].first][r[i][j + 1].first] = min(dis[r[i][j].first][r[i][j + 1].first], r[i][j].second + r[i][j + 1].second);
			dis[r[i][j + 1].first][r[i][j].first] = dis[r[i][j].first][r[i][j + 1].first];
			
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = i; k <= j; k++) {
				if(i != j && i != k && j != k) {
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
	}
	while(q--) {
		cin >> st >> ed;
		cout << w[st] + dis[st][ed] + w[ed] << endl;
	}
	return 0;
}
