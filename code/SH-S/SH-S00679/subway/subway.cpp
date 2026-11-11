#include<bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10, maxm = 5e5 + 10;
int n, m, d, q;
int w[maxm];
vector<pair<int,int> > station[maxm];
long long dis[maxn][maxn];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int _case;
	scanf("%d %d %d %d %d", &_case, &n, &m, &d, &q);
	for(int i = 1; i <= m; i ++){
		scanf("%d", &w[i]);
	}
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			if(i == j)	dis[i][j] = 0;
			else	dis[i][j] = 1e12;
		}
	} 
	for(int i = 1; i <= n; i ++){
		int k, a, t;
		scanf("%d", &k);
		while(k --){
			scanf("%d %d", &a, &t);
			station[a].push_back(make_pair(i, t));
		}
	}
	for(int i = 1; i <= m; i ++){
		for(int x = 0; x < station[i].size(); x ++){
			for(int y = 0; y < x; y ++){
				int u = station[i][x].first, v = station[i][y].first;
				long long dis_uv = station[i][x].second + station[i][y].second;
				dis[u][v] = min(dis[u][v], dis_uv);
				dis[v][u] = min(dis[v][u], dis_uv);
			}
		}
	}
	for(int k = 1; k <= n; k ++){
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= n; j ++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q --){
		int s, t;
		long long ans = LLONG_MAX;
		cin >> s >> t;
		for(int i = 0; i < station[s].size(); i ++){
			for(int j = 0; j < station[t].size(); j ++){
				int u = station[s][i].first, v = station[t][j].first;
				ans = min(ans, dis[u][v] + station[s][i].second + station[t][j].second);
			}
		}
		ans += w[s] + w[t];
		printf("%lld\n",ans);
	} 
	return 0;
}
