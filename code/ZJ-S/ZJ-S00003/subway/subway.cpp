#include<bits/stdc++.h>
using namespace std;
// n <= 500 m <= 5e5 d <= 20 q <= 1e5

int w[500005];
int k[505];
int t[505][500005];
vector<pair<int, int>> sta2rai[500005];
long long dp[505][505];
using PII = pair<int, int>;
int ed[505][505]; // 0 => no edge
int c, n, m, d, q; 
void init(){
	// remains 2h. can i do it?
	for(int i=1;i<=m;i++){
		for(PII A: sta2rai[i]){
			for(PII B: sta2rai[i]){
				if(A.first==B.first) continue;
				int val = t[A.first][A.second] + t[B.first][B.second];
				if(ed[A.first][B.first] == 0){
					ed[A.first][B.first]
				  = ed[B.first][A.first]
				  = val;
				}else{
					ed[A.first][B.first]
				  = ed[B.first][A.first]
				  = min(val,
				    ed[B.first][A.first]);
				}
			}
		}
	}
}
void floyd(){
	memset(dp, 0x3f, sizeof dp);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	dp[i][j] = (!ed[i][j] && i != j)?0x3f3f3f3f3f3f3f3fll:ed[i][j];
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				dp[j][i] = min(dp[j][i], dp[i][k] + dp[k][j]);
			}
		}
	}
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	// feropen  freopn fropen  subway.in, "w", stdin  joke others
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q; // sliverfish ccf
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			int AA;
			cin >> AA >> t[i][j];
			sta2rai[AA].push_back({i, j});
		}
		// @grassblockeggs i'm doing csp-s
		// @zhangfanfan you are sliverfish
	}
	init();
	floyd();
	int x, y;
	while(q--) {
		cin >> x >> y;
		long long ans = 0x3f3f3f3f3f3f3f3fll;
		for(PII i: sta2rai[x]){
			for(PII j: sta2rai[y]){
				ans = min(ans, dp[i.first][j.first] + t[i.first][i.second] + t[j.first][j.second]);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
}
// i wanna to cry 
// but the problem is squared the sum of e and z minus the sum of squared e and squared z~~~ 
// let's counting star  
// ok it may tle
// i need to ... no!    i not do oxygen 2!!!!
// 0.6565ms!!! right!!!