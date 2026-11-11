#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back
#define _1 first
#define _2 second
#define pii pair<int, int>
using namespace std;

const int N = 505, M = 5e5 + 5, D = 25, Q = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int c, n, m, k[N], d, q, dist[M];
int w[M], a[N][25], t[N][25];
int x[Q], y[Q];
vector<pii > g[M];

void bfs(int x){
	queue<pii > q;
	q.push({x, 0}), dist[x] = 0;
	while(!q.empty()){
		int u = q.front()._1, fa = q.front()._2;
		q.pop();
		for(auto v : g[u]){
			if(v._1 == fa) continue;
			if(dist[v._1] > dist[u] + 2 * t[v._2][v._1]){
				dist[v._1] = dist[u] + 2 * t[v._2][v._1];
				q.push({v._1, u});
			}
		}
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++)
			cin >> a[i][j] >> t[i][j];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 2; j <= k[i]; j++)
			g[a[i][j]].pb({a[i][j - 1], i}), g[a[i][j - 1]].pb({a[i][j], i});
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		for(int i = 1; i <= m; i++)
			dist[i] = inf;
		bfs(x);
		cout << dist[y] + w[x] + w[y] << endl;
	}
	return 0;
}
/*
一年内水平没有任何进步
recall recall recall 
*/
