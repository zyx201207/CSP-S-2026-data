#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ar array<int, 4>
#define arr array<int, 3>
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	//每次站内换乘都需要从一条线路的站台先走到站厅，再从站厅走到另一条线路的站台。每个出行计划的总步行时间为进出站和换乘的步行时间之和。-
	int c, n, m, d, Q;
	cin >> c >> n >> m >> d >> Q;
//	if(c==7 || c==8 || c>=9 && c<=11){
//		vector<int> w(m+1);
//		for(int i=1;i<=m;++i){
//			cin >> w[i];
//			// w[i] ： 从该地铁口到站厅所需的时间
//		}
//		vector<ar> a(n+1);
//		for(int i=1;i<=n;++i){
//			int k;
//			cin >> k;
//			int x1, y1, x2, y2;
//			cin >> x1 >> y1 >> x2 >> y2;
//			a[i]={x1, y1, x2, y2};
//		}
//		while(Q--){
//			int u, v;
//			cin >> u >> v;
//			int cost=w[u]+w[v];
//			for(int i=1;i<=n;++i){
//
//			}
//		}
//	}
	if(c==20 || c==21 || n==2){
		vector<int> w(m+1);
		for(int i=1;i<=m;++i){
			cin >> w[i];
			// w[i] ： 从该地铁口到站厅所需的时间
		}
		vector<vector<ar>> a(n+1, vector<ar>());
		for(int i=1;i<=n;++i){
			int k;
			cin >> k;
			a[i].resize(k+1);
			for(int j=1;j<=k;++j){
				int x, y;
				cin >> x >> y;
				a[i][j]={x, y};
			}
		}
		while(Q--){
			int u, v;
			cin >> u >> v;
			int len=a[1].size(), flag=0;
			for(int j=1;j<len;++j){
				if(a[1][j][0]==u) flag++;
				if(a[1][j][0]==v) flag++;
			}
			if(flag==2){
				cout << w[u]+w[v] << endl;
			}else{
				int len1=a[1].size(), len2=a[2].size();
				int co=INT_MAX;
				for(int i=1;i<len1;++i){
					for(int j=1;j<len2;++j){
						if(a[1][i][0]==a[2][j][0]){
							co=min(co, a[1][i][1]+a[2][j][1]);
						}
					}
				}
				cout << w[u]+w[v]+co << endl;
			}
		}
	}else{
		vector<int> w(m+1);
		for(int i=1;i<=m;++i){
			cin >> w[i];
			// w[i] ： 从该地铁口到站厅所需的时间
		}
		vector<vector<array<int, 2>>> e(n*m+1, vector<array<int, 2>>());
		for(int i=1;i<=n;++i){
			int k;
			cin >> k;
			int fx=-1, fy=-1;
			int lx=-1, ly=-1;
			for(int j=1;j<=k;++j){
				int xx, yy;
				cin >> xx >> yy;
				if(j==1) fx=xx, fy=yy;
				// 第 i 条线路经过的地铁站编号  从该地铁站的站厅到第 i 条线路的站台所需的时间
				if(lx=-1 && ly==-1){
					lx=xx, ly=yy;
					continue;
				}
				if(e[xx].size()>0){
					int len=e[xx].size();
					for(int q=0;q<len;++q){
						int u=e[xx][q][0], v=m*(i-1)+xx, w=e[xx][q][1];
						e[u].push_back({v, w+yy}), e[v].push_back({u, w+yy});
					}
				}
				int nu=m*(i-1)+lx, nv=m*(i-1)+xx;
				e[nu].push_back({nv, 0}), e[nv].push_back({nu, 0});
				lx=xx, ly=yy;
			}
			int nu=m*(i-1)+fx, nv=m*(i-1)+lx;
			e[nu].push_back({nv, 0}), e[nv].push_back({nu, 0});
		}
		auto dijkstra = [&](int st) -> vector<int>{
			vector<int> dis(n*m+1, 0x3f3f3f3f), vis(n*m+1, 0);
			priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
			for(int i=1;i<=n;++i){
				int u=(i-1)*m+st;
				dis[u]=0;
				if(e[u].size()>0){
					q.push({dis[u], u});
				}
			}
			while(!q.empty()){
				int u=q.top()[1]; q.pop();
				if(vis[u]) continue;
				vis[u]=1;
				int len=e[u].size();
				for(int j=0;j<len;++j){
					int v=e[u][j][0], w=e[u][j][1];
					if(dis[u]+w<dis[v]){
						dis[v]=dis[u]+w;
						q.push({dis[v], v});
					}
				}
			}
			return dis;
		};
		vector<arr> a;
		for(int i=1;i<=Q;++i){
			int x, y;
			cin >> x >> y;
			// 起点和终点所在的地铁站编号
			a.push_back({x, y, i});
		}
		sort(a.begin(), a.end(), [&](arr xx, arr yy){
			return xx[0]<yy[0];
		});
		vector<int> ans(Q+1, 0x3f3f3f3f), dis;
		int lx=-1;
		for(int i=0;i<Q;++i){
			if(lx!=a[i][0]){
				lx=a[i][0];
				dis=dijkstra(a[i][0]);
			}
			if(lx==a[i][0]){
				for(int j=1;j<=n;++j){
					int u=(j-1)*m+a[i][1];
					ans[a[i][2]]=min(ans[a[i][2]], dis[u]);
				}
			}
		}
		for(int i=1;i<=Q;++i){
			cout << ans[i] << endl;
		}
	}
	return 0;
}