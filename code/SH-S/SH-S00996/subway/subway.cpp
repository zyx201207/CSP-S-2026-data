#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 500 + 32;
const int M = 5e5 + 32;
int c, n, m, d, q;
ll w[N];
int k;
ll a[M], t[M];
int x, y;
struct type{
	int v, w;
};
vector<type> e[M];
void init(){
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i)	cin >> w[i];
	for(int i = 1; i <= n; ++i){
		cin >> k;
//		for(int j = 1; j <= k; ++j){
//			cin >> a >> t;
//			if(j == 1){
//				preva = a;
//				prevt = t;
//				continue;
//			}
//			int u = preva;
//			int v = a;
//			int w = prevt + t;
//			e[u].push_back({v, w});
//			e[v].push_back({u, w});
//		}
		for(int j = 1; j <= k; ++j){
			cin >> a[j] >> t[j];
		}
		for(int j = 1; j <= k; ++j){
			for(int jj = j + 1; jj <= k; ++jj){
				int u = a[j], v = a[jj];
				ll w = t[j] + t[jj];
//				cout << u << " " << v << " "<<w << "()\n";
				e[u].push_back({v, w});
				e[v].push_back({u, w});
			}
		}
	}
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6*/
ll dis[M];
bool vis[M];
struct pqcmp{
	int num, id;
	bool operator< (pqcmp x) const{
		return num > x.num;
	}
};
priority_queue<pqcmp> pq;
void mmst(int st){
	for(int i = 1; i <= m; ++i)	dis[i] = 1e9 + 7;
	dis[st] = 0;
	while(!pq.empty())	pq.pop();
	pq.push({0, st});
	for(int i = 1; i <= m; ++i)	vis[i] = false;
}
int Dij(int s, int t){
	mmst(s);
	for(int rnd = 1; rnd <= m - 1; ++rnd){
		pqcmp tmp = pq.top();
		int u = tmp.id;
//		cout << tmp.id << " " << tmp.num <<"Phase1\n";
		pq.pop();
		vis[u] = true;
		for(int xh = 0; xh < e[u].size(); ++xh){
			int v = e[u][xh].v;
			int w = e[u][xh].w;
//			cout << v << " " << w <<" " << dis[v] << " " <<dis[u] << " " << w << "Phase2\n";
			
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
//				cout << v << " " << w <<" " << dis[v] << " " <<dis[u] << " " << w << "Phase3\n";
				pq.push({dis[v], v});
			}
		}
	}
	return dis[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
	while(q--){
		cin >> x >> y;
		int ans = w[x] + w[y];
		ans += Dij(x, y);
		cout << ans << "\n";
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
