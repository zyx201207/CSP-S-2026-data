#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 505,M = 5e5 + 5;
int c,n,m,d,q;
int w[M];
struct node{
	int v,w;
}; 
vector<node> b[M]; // 地铁站经过的线路 
int dist[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	memset(dist,0x3f,sizeof dist);
	for(int i = 1;i <= n;i++) dist[i][i] = 0; 
	for(int i = 1;i <= n;i++){
		int k;cin >> k;
		for(int j = 1;j <= k;j++){
			int x,y;cin >>x >> y;
			b[x].push_back({i,y});
		}
	}
	// 求出从线路 i 换乘到线路 j 所需时间 
	for(int i = 1;i <= m;i++){
		for(auto j:b[i]){
			for(auto k:b[i]){
				int u = j.v,v = k.v,w = j.w + k.w;
				dist[u][v] = min(dist[u][v],w);
			}
		}
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				dist[i][j] = min(dist[i][j],dist[i][k] + dist[j][k]);
			}
		}
	}
	while(q--){
		int x,y;cin >> x >> y;
		int ans = 1e18;
		for(auto i:b[x]){
			for(auto j:b[y]){
				int u = i.v,v = j.v;
				int cst = i.w + j.w;
				ans = min(ans,w[x] + w[y] + cst + dist[u][v]);
			}
		}
		cout << ans << "\n";
	} 
	return 0;
}

