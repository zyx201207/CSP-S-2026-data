#include<bits/stdc++.h>
using namespace std;
#define int long long  
const int N = 505;
const int M = 500 * 505;
int c, n, m, d, q, ans;
int w[M], k[N], a[N][M];
bool vis[N];
vector<int> G[N];
int dfs(int x){
	if()
	vis[x] = 1;
	ans += t[]
	int len = G[x].size();
	for(int i = 0; i < len; i++){
		dfs(G[x][i]);
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			cin >> a[i][j];
			G[a[i][j - 1]].push_back(j);
			G[j].push_back(a[i][j - 1]);
		}
	}
	for(int i = 1; i <= q; i++){
		int x, y;
		cin >> x >> y;
		ans = 0;
	}
	return 0;
}

