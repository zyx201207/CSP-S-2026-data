#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+10;
vector<pair<int, int>> g[N];
int a[N];
int b[N];
int h[N];
int dis[N];
int dk(int st, int ed){
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pair<int, int>,vector<pair<int, int>>, greater<>> pq;
	dis[st] = 0;
	pq.push({0, st});
	while (pq.size()){
		auto f = pq.top();
		pq.pop();
		int u = f.second;
		int w = f.first;
		if (dis[u] < w){
			continue;
		}
		//cout << u <<"\n";
		for (auto v : g[u]){
			if (dis[v.second] > dis[u] + v.first){
				dis[v.second] = dis[u] + v.first;
				pq.push({dis[v.second], v.second}); 
			}
		}
	}
	return dis[ed];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++){
			int s, t;
			cin >> s >> t;
			b[s] = t;
			h[j] = s;
			for (int l = 1; l < j; l++){
				int w = b[h[l]] + t;
				g[s].push_back({w, h[l]});
				g[h[l]].push_back({w, s});
			}
		}
	}
	while (q--){
		int x, y;
		cin >> x >> y;
		cout << dk(x, y) + a[x] + a[y]<< "\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/
