#include<bits/stdc++.h>
using namespace std;
#define int long long
const int L = 5e2 + 5;
const int S = 5e5 + 5;
const int Q = 1e5 + 5;
int c, n, m, d, q, w[S];
struct subway{int id, t;};
vector<subway> sg[S];
int dp[Q][L];
int dis[L][L], f[L][L];
int x[Q], y[Q], to[S], top;
void Floyd(){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			f[i][j] = dis[i][j];
	for(int k = 1; k <= n; k++)
		for(int i = 1; i < k; i++)
			for(int j = 1; j < k; j++)
			 	f[k][i] = f[i][k] = min(f[i][k], f[i][j] + f[j][k]);
	return void();
}
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)cin >> w[i];
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= n; i++)dis[i][i] = 0;
	for(int i = 1; i <= n; i++){
		int top, x, t;
		cin >> top;
		while(top--){
			cin >> x >> t;
			for(auto v : sg[x])dis[v.id][i] = dis[i][v.id] = min(dis[v.id][i], t + v.t);
			sg[x].push_back({i, t});
		}
	}
	for(int i = 1; i <= q; i++){
		cin >> x[i] >> y[i];
		if(!to[x[i]])to[x[i]] = ++top;
	}
	Floyd();
	for(int i = 1; i <= m; i++){
		if(!to[i])continue;
		int k = to[i];
		for(int j = 1; j <= n; j++){
			dp[k][j] = 1e18;
			for(auto v : sg[i])dp[k][j] = min(dp[k][j], v.t + f[v.id][j]);
		}
	}
	for(int i = 1; i <= q; i++){
		int Ans = 1e18;
		for(auto v : sg[y[i]]){
			Ans = min(Ans, dp[to[x[i]]][v.id] + v.t);
		}
		Ans += w[x[i]] + w[y[i]];
		cout << Ans << endl;
	}
	return 0;
}