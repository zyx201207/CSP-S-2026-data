#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005],k[501],x[100005],y[100005],dis[400],vis[400];
vector <int> a[501];
vector <int> t[501];
vector < pair <int,int> > _[400];
int dij(int S,int T){
	priority_queue < pair <int,int> > q;
	fill(dis + 1,dis + m + n + 1,1e18);
	fill(vis + 1,vis + m + n + 1,0);
	dis[S] = 0;
	q.push({0,S});
	while (q.size()){
		int u = q.top().second;
		q.pop();
		if (vis[u]){
			continue;
		}
		vis[u] = 1;
		for (int i = 0;i < _[u].size();i++){
			int V = _[u][i].first;
			int W = _[u][i].second;
			if (dis[V] > dis[u] + W){
				dis[V] = dis[u] + W;
				q.push({-dis[V],V});
			}
		}
	}
	return dis[T];
}
void solve1(){
	for (int i = 1;i <= q;i++){
		cout << dij(x[i],y[i]) + w[x[i]] + w[y[i]] << "\n";
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++){
		cin >> k[i];
		for (int j = 1;j <= k[i];j++){
			int aa,tt;
			cin >> aa >> tt;
			if (c <= 6){
				_[aa].push_back({m + i,tt});
				_[m + i].push_back({aa,tt});
			}
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
	}
	for (int i = 1;i <= q;i++){
		cin >> x[i] >> y[i];
	}
	if (c <= 6){
		solve1();
	}
	else if (c <= 11){
		solve2();
	}
//	else if (c <= 19){
//		solve3();
//	}
//	else if (c <= 21){
//		solve4();
//	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/