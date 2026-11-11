#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int c, n, m, d, q;
int w[N], s, f;
struct st{
	int u, t;
}; vector<st> a[N];
struct stu{
	int u, t, v;
};
int bfs(int ks){
	queue<stu> q; int x = a[s][ks].u;
	q.push({s, w[s]+a[s][ks].t, x});
	while(!q.empty()){
		stu u = q.front(); q.pop();
		if(u.u == f){
			return u.t + w[f];
		}
		for(int i = 1; i <= m; i++){
			for(auto j : a[i]){
				if(j.u == u.v){
					q.push({i, u.t+j.t, u.v});
					break;
				}
			}
		}
		for(auto it : a[u.u]){
			q.push({u.u, u.t+it.t, it.u});
		}
	}
	return 0;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int x, y; cin >> x >> y;
			a[x].push_back({i, y});
		}
	}
	while(q--){
		cin >> s >> f; int ans = 1e9+10;
		for(auto it : a[s]){
			ans = min(ans, bfs(it.u));
		}
		cout << ans << "\n";
	}
	return 0;
}