//Ñîð©Ñ­ SN-S00488 
#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace sol{
	int W[500005];
	vector<pair<int,int>> tra[500005];
	int dis[505][505]; 
	void main(){
		int c,n,m,d,q;
		cin >> c >> n >> m >> d >> q;
		for(int i = 1;i <= m;++i){
			cin >> W[i];
		}
		memset(dis,0x3f,sizeof(dis));
		for(int i = 1;i <= n;++i){
			int k;
			cin >> k;
			for(int j = 1;j <= k;++j){
				int a,t;
				cin >> a >> t;
				tra[a].push_back({i,t});
			}
			dis[i][i] = 0;
		}
		
		for(int i = 1;i <= m;++i){
			for(int j = 0;j < tra[i].size();++j){
				for(int k = j;k < tra[i].size();++k){
					int u = tra[i][j].first, v = tra[i][k].first, 
					    w = tra[i][j].second + tra[i][k].second;
					    
					dis[u][v] = dis[v][u] = min({dis[u][v], dis[v][u], w});
				}
			}
		}
		
		for(int k = 1;k <= n;++k){
			for(int i = 1;i <= n;++i){
				for(int j = 1;j <= n;++j){
					if(dis[i][k] + dis[k][j] <= dis[i][j]){
						dis[i][j] = dis[i][k] + dis[k][j];
					}
				}
			}
		}
		
		for(int i = 1;i <= q;++i){
			int l,r;
			cin >> l >> r;
			
//			cout << "# " << tra[l].size() << " " << tra[r].size() << endl;
			
			int ans = 0x3f3f3f3f3f3f3f3f;
			
			for(int j = 0;j < tra[l].size();++j){
				for(int k = 0;k < tra[r].size();++k){
					int u = tra[l][j].first, v = tra[r][k].first;
//					cout << u << " " << v << " " << dis[u][v] << endl;
					ans = min(ans, W[l]+W[r] + tra[l][j].second + tra[r][k].second + dis[u][v]);
				}
			}
			cout << ans << endl;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	sol::main();
}
/*
feat: initial commit
chore: add samples
fix: readin error
feat: add fileio
pref: io

end at 15:45
*/
