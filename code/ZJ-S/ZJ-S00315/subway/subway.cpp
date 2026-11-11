#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,t;
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c, n, m , d, q;
	cin >> c >> n >> m >> d >> q;
	vector<int> w(m + 1);
	vector<node> g[500005];
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		vector<int> a(k + 1), t(k + 1);
		for(int j = 1; j <= k; j++) {
			cin >> a[j] >> t[j];
		}
		for(int j = 1; j <= k; j++) {
			for(int l = 1; l <= k; l++){
				if(l == j) continue;
				g[a[j]].push_back((node){a[l],t[l]});
				g[a[l]].push_back((node){a[j],t[j]});
			}
		}
	}
	
	while(q--){
		int x,y;
		vector<bool> vis(m + 1, 0);
		vector<int> dis(m + 1, 0);
		cin >> x >> y;
		queue<int> q;
		q.push(x);
		while(!q.empty()){
			int qx = q.front();q.pop();
			for(int i = 0; i < (int)g[qx].size(); i++) {
				node xx = g[qx][i];
				if(vis[xx.v]) continue;
				if(dis[qx] + xx.t < dis[xx.v]) {
					dis[xx.v] = dis[qx] + xx.t;
					vis[xx.v] = true;
					q.push(xx.v);
				}
			}
		}
		cout << dis[y] + w[x] + w[y] << '\n';
	}
	return 0; 
}
