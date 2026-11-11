#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 505, M = 5e5 + 10;

int c, n, m, d, Q, id;
int w[M];
struct node{
	int to, ti;
	bool operator < (const node &x) const {
		return ti > x.ti;
	}
};
vector<node> v[M << 2];
int xidl[M << 2], xidr[M << 2];
bool vis[100000];
int dis[7000][7000];
priority_queue<node> q;
void Dij(int s){
	while(!q.empty()) q.pop();
	memset(vis, false, sizeof vis);
	dis[s][s] = 0;
	q.push({s, 0});
	while(!q.empty()){
		int k = q.top().to; q.pop();
		if(vis[k]) continue ;
		vis[k] = false;
		if(k > m){
			for(int i = xidl[k];i <= xidr[k];i ++){
				if(dis[s][i] > dis[s][k]){
					dis[s][i] = dis[s][k];
					q.push({i, dis[s][i]});
				}
			}
		}
		for(auto i : v[k]){
			if(dis[s][i.to] > dis[s][k] + i.ti){
				dis[s][i.to] = dis[s][k] + i.ti;
				q.push({i.to, dis[s][i.to]});
			}
		}
	}
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> Q;
	id = m;
	for(int i = 1;i <= m;i ++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i ++){
		int k; cin >> k;
		int idl = id + 1, idr = id + k - 1;
		for(int j = 1;j <= k;j ++){
			int a, t; cin >> a >> t;
			if(j < k) id ++;
			xidl[id] = idl, xidr[id] = idr;
			if(j == 1 || j == k){
				v[a].push_back({id, t});
				v[id].push_back({a, t});
			} else {
				v[a].push_back({id, t});
				v[id].push_back({a, t});
				v[a].push_back({id - 1, t});
				v[id - 1].push_back({a, t});
			}
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1;i <= m;i ++){
		Dij(i);
	}
	while(Q --){
		int x, y;
		cin >> x >> y;
		cout << dis[x][y] + w[x] + w[y] << endl;
	}
	return 0;
}