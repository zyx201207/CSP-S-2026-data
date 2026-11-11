#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int M = 5e5+5;
//注意long long 
int c,n,m,d,q;
long long w[M];
int k[N];
long long dp[N][N];
vector<pair<int,long long> > vc[M];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++){
		cin >> w[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			dp[i][j] = 1e18;
		}
	}
	for(int i=1; i<=n; i++){
		cin >> k[i];
		dp[i][i] = 0;
		for(int j=1; j<=k[i]; j++){
			int x;
			long long y;
			cin >> x >> y;
			vc[x].push_back(make_pair(i,y));
		} 
	}
	for(int i=1; i<=m; i++){
		for(int j=0; j<vc[i].size(); j++){
			int u = vc[i][j].first;
			long long w1 = vc[i][j].second;
			for(int k=0; k<vc[i].size(); k++){
				int v = vc[i][k].first;
				long long w2 = vc[i][k].second;
				dp[u][v] = min(dp[u][v],w1+w2);
			}
		}
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	long long ans;
	for(int i=1; i<=q; i++){
		int x,y;
		cin >> x >> y;
		ans = 1e18;
		for(int j=0; j<vc[x].size(); j++){
			int u = vc[x][j].first;
			long long w1 = vc[x][j].second;
			for(int k=0; k<vc[y].size(); k++){
				int v = vc[y][k].first;
				long long w2 = vc[y][k].second;
				ans = min(ans,dp[u][v]+w1+w2);
			}
		}
		cout << ans+w[x]+w[y] << '\n';
	}
	return 0;
} 