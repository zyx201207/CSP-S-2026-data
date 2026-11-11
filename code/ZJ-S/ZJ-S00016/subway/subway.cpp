#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,d,Q;
const int N = 6e5+5,M = 5e5+5,K = 505;
vector<pair<int,int> > G[N];
int w[N];
inline void add(int u,int v,int w){
	G[u].push_back(make_pair(v,w));
	G[v].push_back(make_pair(u,w));
}
int dis[N];
int tran[K][K];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> T >> n >> m >> d >> Q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1,k;i <= n;i++){
		cin >> k;
		for(int j = 1,v,w;j <= k;j++){
			cin >> v >> w;
			add(m+i,v,w);
		}
	}
	memset(tran,63,sizeof(tran));
	for(int i = 1;i <= n;i++) tran[i][i] = 0;
	for(int i = 1;i <= m;i++){
		for(auto [vx,wx] : G[i]){
			for(auto [vy,wy] : G[i]){
				if(vx != vy){
					tran[vx-m][vy-m] = wx + wy;
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			for(int k = 1;k <= n;k++){
				if(tran[i][k] < 1ll<<60 && tran[k][j] < 1ll<<60){
					tran[i][j] = min(tran[i][j],tran[i][k] + tran[k][j]);
					tran[j][i] = tran[i][j];
				}
			}
		}
	}
	int x,y;
	while(Q--){
		cin >> x >> y;
		int ans = 1ll<<60;
		for(auto [vx,wx] : G[x]){
			for(auto [vy,wy] : G[y]){
				ans = min(ans,wx+wy+tran[vx-m][vy-m]);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}