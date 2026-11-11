#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll c, n, m, d, q, w[N], k[N], b[505][505], dp[505][505], minn=0;
vector<pair<ll,ll>> ss[505];
vector<pair<ll,ll>> E[N];
void floyd(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j) dp[i][j] = 0;
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c;
	while(c--){
		memset(w, 0, sizeof(w));
		memset(k, 0, sizeof(w));
		memset(b, 0, sizeof(w));
		memset(dp, 0, sizeof(w));
		for(int i = 1; i <= 505; i++) ss[i].clear();
		for(int i = 1; i <= N; i++)E[i].clear();
		cin >> n >> m >> d >> q;
		for(int i = 1; i <= m; i++) cin >> w[i];
		for(int i = 1; i <= n; i++){
			cin >> k[i];
			for(int j = 1; j <= k[i]; j++){
				ll x, y;
				cin >> x >> y;
				ss[x].push_back({i, y});
				//cout << x << y << endl;
			}
		}
		memset(dp, 0x3f, sizeof(dp));
		for(int i = 1; i <= m; i++){
			for(auto u : ss[i]){
				ll v = u.first, w = u.second;
				for(auto u2 : ss[i]){
					ll v2 = u2.first, w2 = u2.second;
					ll time_use = w + w2;
					dp[v][v2] = min(dp[v][v2], time_use);
					dp[v2][v] = dp[v][v2];
				}
			}
		}
		floyd();
		for(int i = 1; i <= q; i++){
			ll x, y, minn = 1e18;
			cin >> x >> y;
			for(auto u : ss[x]){
				ll v1 = u.first, w1 = u.second;
				for(auto u2: ss[y]){
					ll v2 = u2.first, w2 = u2.second;
					//cout << w[x] << " " << w1 << " " << dp[v1][v2] << " " << w2 << " " << w[y] << endl;
					minn = min(minn, w[x] + w1 + dp[v1][v2] + w2 + w[y]);
				} 
			}
			cout << minn << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
