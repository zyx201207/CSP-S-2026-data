#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int N = 6e5 + 5;
int c, n, m, d, q;
vector<int>v[N], w[N];
int aw[N];
long long dis[N];
bool vis[N];
void add(int x, int y, int z){
	v[x].push_back(y);
	v[y].push_back(x);
	w[x].push_back(z);
	w[y].push_back(z);
}
void dijkstra(int s, int t){
	memset(dis, 0x3f3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	priority_queue<pii, vector<pii>, greater<pii> >q;
	q.push({aw[s], s});
	dis[s] = aw[s];
	while(!q.empty()){
		int x = q.top().second;q.pop();
		if(x == t) {
			cout << dis[t] + aw[t];
			return;
		}
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = 0; i < v[x].size(); i++){
			int y = v[x][i], ww = w[x][i];
			if(dis[x] + ww < dis[y]){
				dis[y] = dis[x] + ww;
				q.push({dis[y], y});
			}
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> aw[i];
	for(int i = 1; i <= n; i++){
		int k; cin >> k;
		for(int j = 1; j <= k; j++){
			int a, t; cin >> a >> t;
			add(m + i, a, t);
		}
	}
	while(q--){
		int x, y; cin >> x >> y;
		dijkstra(x, y);
		cout << "\n";
	}
	return 0;
}
