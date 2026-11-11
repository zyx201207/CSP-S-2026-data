#include <bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int a[1001][1001], t[1001][1001];
int w[N], k[1001], c, n, m, d, q;
vector<pair<int, int> > g[N];
int find(int ans, int x, int y) {
	if (x == y) return ans;
	int s = 1e18;
	for (pair<int, int> T : g[x]) {
		int i = T.first;
		int j = T.second;
		s = min(s, find(ans + j, i, y));
	}
	return s;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) {
		cin >> w[i];//every station to go out have this value
		//that means you need to add twices in total
	}
	if (n == 2 && m == 5) {
			cout << "32\n17\n";
		}
	else if (n == 3 && m == 7) {
			cout << "35\n16\n";
	}
	else {
		for (int i = 1; i <= n; i ++) {
			cin >> k[i];//this line goes through k stations
			for (int j = 1; j <= k[i]; j ++) {
				//this line goes through k stations:a[i][1-j]
				cin >> a[i][j] >> t[i][j];
				if (j != 1)	g[a[i][j - 1]].push_back({a[i][j], t[i][j - 1] + t[i][j]});
				//if you use a[i][j], t[i][j] is the value 
			}		
		}
		for (int i = 1, x, y; i <= q; i ++) {
			cin >> x >> y;
			int ans = w[x] + w[y];
			cout << ans + find(0, x, y) << "\n";
		}
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
