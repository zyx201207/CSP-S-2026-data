#include <bits/stdc++.h>
using namespace std;

long long c, n, m, d, q, r, ans=0x3f3f3f3f; 
struct Stop{
	int out_t, ways=1;
	int route[55]={-1,-1,-1,-1,-1};
} w[312];
long long routes[55][312], r_cnt[355];
long long s, e;
bool vis[312];

void dfs(int from, int to){
	if (from == to){
		r += w[to].out_t;
		if (r < ans) ans = r;
		r -= w[to].out_t;
		return;
	}
	vis[from] = 1;
	for (int i = 1; i <= n; i++){
		if (w[from].route[i] != -1){
			r += w[from].route[i];
			for (int j = 1; j <= r_cnt[i]; j++){
				if (!vis[routes[i][j]]) {
					r += w[routes[i][j]].route[i];
					dfs(routes[i][j], to);
					r -= w[routes[i][j]].route[i];
				}
			}
			r -= w[from].route[i];
		}
	}
	vis[from] = 0;
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i].out_t;
	}
	for (int i = 1; i <= n; i++){
		cin >> r_cnt[i];
		for (int j = 1; j <= r_cnt[i]; j++){
			int s, t;
			cin >> s >> t;
			routes[i][j] = s;
			w[s].route[i] = t;
		}
	}
	for (int i = 1; i <= q; i++){
		ans = 0x3f3f3f3f;
		cin >> s >> e;
		dfs(s, e);
		ans += w[s].out_t;
		cout << ans << endl;
	}
    return 0;
}

//°ÚÁË£¬Ð´¸öDFSÃþµô 
