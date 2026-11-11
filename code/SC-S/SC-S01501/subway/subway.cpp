#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500005
typedef pair<int, int> pii;
int c, n, m, d, q;
int w[N];
vector<int>g[N];
vector<int>can[N];
int t[2005][505];
int dis[2005][505];
bool vis[2005][505];
int h[2005][505];
struct node{
	int dis, id, l;
	bool operator < (const node &e)const{
		return dis > e.dis;
	}
};
inline int dij(int s, int r){
	memset(dis, 0x3f3f3f3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	priority_queue<node>q;
	for (auto l : can[s]) {
		dis[s][l] = w[s] + t[s][l];
		q.push(node{w[s] + t[s][l], s, l});
	}
	while(!q.empty()){
		auto [__, u, l] = q.top();
		q.pop();
		if (vis[u][l]) continue;
		vis[u][l] = 1;
		//cout << dis[u][l] << " " << u << " " << l << '\n';
		for (auto v : g[u]){
			for (auto now : can[v]){
				if (l == now){
					if (dis[u][l] < dis[v][l]){
						dis[v][l] = dis[u][l];
						q.push(node{dis[v][l], v, l});
					}
				}
				else {
					if (t[u][now] || h[u][l] != v) continue;
					if (v != r){
						if (dis[u][l] + t[v][l] + t[v][now] < dis[v][now]){
							dis[v][now] = dis[u][l] + t[v][l] + t[v][now];
							q.push(node{dis[v][now], v, now});
						}
					}
					else {
						if (dis[u][l] + t[v][l] < dis[v][now]){
							dis[v][now] = dis[u][l] + t[v][l];
							q.push(node{dis[v][now], v, now});
						}
					}
				}
			}
		}
	}
	int ans = 1e18;
	for (auto v : can[r])
		ans = min(ans, dis[r][v] + t[r][v]);
	return ans + w[r];
}
signed main(){
#ifndef LCY
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
#else
#endif
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1, num; i <= n; i++){
		cin >> num;
		int la;
		for (int j = 1, a; j <= num; j++){
			cin >> a >> c;
			if (j != 1){
				h[la][i] = a;
				g[la].push_back(a);
				g[a].push_back(la);
			}
			la = a;
			if (a <= 2000) t[a][i] = c;
			can[a].push_back(i);
		}
	}
	if (m <= 2000){
		while(q--){
			int s, r; cin >> s >> r;
			cout << dij(s, r) << '\n';
		}
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/