#include <bits/stdc++.h>
using namespace std;

long long c, n, m, d, q, w[(int)5e5 + 7], k[500 + 7], dis[500 + 7][500 + 7];

vector<pair<int, int> > p[(int)5e5 + 7];

vector<long long> a[500 + 7], t[500 + 7];

struct pnt{
	int v;
	long long w;
};

vector<pnt> g[500 + 7];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++){
		scanf("%lld", &w[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%lld", &k[i]);
		for(int j = 0; j < k[i]; j++){
			long long x, y;
			scanf("%lld%lld", &x, &y);
			a[i].push_back(x);
			t[i].push_back(y);
			p[x].push_back(make_pair(i, j));
		}
	}
	for(int i = 1; i <= m; i++){ // O(md^2)
		int siz = p[i].size();
		for(int j = 0; j < siz; j++){
			for(int j2 = j + 1; j2 < siz; j2++){
				g[p[i][j].first].push_back((pnt){p[i][j2].first, t[p[i][j].first][p[i][j].second] + t[p[i][j2].first][p[i][j2].second]});
                                g[p[i][j2].first].push_back((pnt){p[i][j].first, t[p[i][j].first][p[i][j].second] + t[p[i][j2].first][p[i][j2].second]});
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			dis[i][j] = dis[j][i] = (1LL << 62);
		}
	}
	for(int i = 1; i <= n; i++){
		int siz = g[i].size();
		for(int j = 0; j < siz; j++){
			dis[i][g[i][j].v] = dis[g[i][j].v][i] = g[i][j].w;
		}
	}
	for(int k = 1; k <= n; k++){ // O(n^3)
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(dis[i][k] + dis[j][k] < 0) continue;
				dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[j][k]);
			}
		}
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++){
//			printf("%lld%c", dis[i][j], " \n"[j == n]);
//		}
//	}
	while(q--){
		int x, y;
		scanf("%d%d", &x, &y);
		int sizx = p[x].size(), sizy = p[y].size();
		long long ansxy = (1LL << 62);
		for(int i = 0; i < sizx; i++){
			for(int j = 0; j < sizy; j++){
				ansxy = min(ansxy, dis[p[x][i].first][p[y][j].first] + t[p[x][i].first][p[x][i].second] + t[p[y][j].first][p[y][j].second]);
			}
		}
		printf("%lld\n", ansxy + w[x] + w[y]);
	}
	return 0;
}
