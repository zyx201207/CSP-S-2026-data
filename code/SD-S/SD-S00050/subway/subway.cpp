#include <bits/stdc++.h>
using namespace std;

const int N = 501;
const int M = 100005;
int c, n, m, d, q;
struct E{
	int u;
	long long w;
};
vector<E> e[M];
struct Station{
	int sn = 0;
	int w, t[21], id[21];
} s[M];

long long dis[N][N];bool vis[N];

void dij(int u){
	vis[u] = 1;
	dis[u][u] = 0;
	for (auto x : e[u]){
		dis[u][x.u] = min(dis[u][x.u], x.w);	
	}
	for (auto x : e[u]){
		if (vis[x.u]) return;
		dij(x.u);
		for (int i = 1;i <= m; i++){
			if (u == i) continue;
			dis[u][i] = min(dis[u][i], dis[u][x.u] + dis[x.u][i]);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> s[i].w;
	for (int i = 1; i <= n; i++){
		int k; cin >> k;
		for (int j = 1; j <= k; j++){
			int id, t;
			cin >> id >> t;
			s[id].id[++s[id].sn] = i; s[id].t[s[id].sn] = t;
		}
	}
	for (int i = 1; i <= m; i++)
		if (s[i].sn > 1){
			for (int j = 1; j < s[i].sn; j++)
				for (int k = j+1; k <= s[i].sn; k++){
					e[s[i].id[j]].push_back({s[i].id[k], s[i].t[j] + s[i].t[k]});
					e[s[i].id[k]].push_back({s[i].id[j], s[i].t[j] + s[i].t[k]});
				}
		}
	memset(dis, 0x3f, sizeof(dis));
	while (q--){
		int x, y; cin >> x >> y;
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for (int i = 1; i <= s[x].sn; i++){
			memset(vis, sizeof(vis), 0);
			dij(s[x].id[i]);
			long long mn = 0x3f3f3f3f3f3f3f3f;
			for (int j = 1; j <= s[y].sn; j++){
				mn = min (mn, s[y].t[j] + dis[s[x].id[i]][s[y].id[j]]);
			}
			ans = min(ans, s[x].w + s[y].w + s[x].t[i] + mn);
		}
		cout << ans << "\n";
		
	}
	return 0;
}
