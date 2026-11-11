#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q, x, y; 
int k[505];
int w[500005];
int dp[500005];
vector <int> a[505];
vector <int> t[505];
vector <int> to[500005];
bool vis[500005];
map <int, map <int, int> > jans;
signed main(){
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)  cin >> w[i];
	for (int i = 1; i <= n; i++){
		cin >> k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for (int j = 1; j <= k[i]; j++){
			cin >> x >> y;
			a[i].push_back(x);
			t[i].push_back(y);
			to[x].push_back(i);
		}
	}
	for (int r = 1; r <= q; r++){
		cin >> x >> y;
		if (jans[x][y] != 0){
			cout << jans[x][y] << '\n';
			continue;
		}
		memset (dp, 127, sizeof dp);
		dp[x] = w[x];
		queue <int> q;
		q.push(x);
		while (!q.empty()){
			int u = q.front();
			q.pop();
			for (int i:to[u]){//i代表能从u出发的所有线路
				int fl;
				for (int j = 1; j <= k[i]; j++)
					if (a[i][j] == u){
						fl = j;
						break;
					}
				for (int j = 1; j <= k[i]; j++)
					if (j != fl && dp[a[i][j]] > dp[u] + t[i][fl] + t[i][j]){
						dp[a[i][j]] = dp[u] + t[i][fl] + t[i][j];
						q.push(a[i][j]);
					}
			}
		}
		cout << dp[y] + w[y] << '\n';
		jans[x][y] = dp[y] + w[y];
	} 
	return 0;
}
