#include<bits/stdc++.h>
#define int long long
#define fore(i,a,b) for(int i=(a);i<=(b);++i)
#define repe(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N = 510;
const int M = 5e5 + 10;
// d <= 20
// n <= 500
// m <= 5e5
int c, n, m, d, Q;

vector<pair<int,int>> To[M]; // 20MB
int h[M]; // 4MB
int Dis[N][N]; // 2MB
int Query(int s,int t) {
	int res = 1e18;
	for(pair<int,int> e1 : To[s]) {
		for(pair<int,int> e2 : To[t]) {
			int u = e1.first, v = e2.first;
			res = min(res, e1.second + e2.second + Dis[u][v]);
		}
	}
	return res + h[s] + h[t];
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> Q;
	fore(i, 1, m) cin >> h[i];
	fore(i, 1, n) {
		int k; cin >> k;
		while(k --) {
			int v, w;
			cin >> v >> w;
			To[v].push_back({i, w});
		}
	}
	fore(i, 1, n) {
		fore(j, 1, n) Dis[i][j] = 1e18;
	}
	fore(i, 1, n) Dis[i][i] = 0;
	
	fore(i, 1, m) {
		for(pair<int,int> e1 : To[i]) {
			for(pair<int,int> e2 : To[i]) {
				int u = e1.first;
				int v = e2.first;
				Dis[u][v] = min(Dis[u][v], e1.second + e2.second);
				Dis[v][u] = min(Dis[v][u], e1.second + e2.second);
			}
		}	
	}
	fore(k, 1, n) {
		fore(i, 1, n) {
			if(Dis[i][k] >= 1e18) continue;
			fore(j, 1, n) {
				if(Dis[k][j] >= 1e18) continue;
				if(i == j) continue;
				Dis[i][j] = min(Dis[i][j], Dis[i][k] + Dis[k][j]);
			}
		}
	}
	while(Q --) {
		int s, t;
		cin >> s >> t;
		cout << Query(s, t) << '\n';
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


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/







