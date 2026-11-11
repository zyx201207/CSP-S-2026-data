#include<bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

struct node{
	long long x;
	long long k;
	friend bool operator<(node x, node y){
		if(x.k == y.k) return x.x > y.x;
		return x.k > y.k;
	}
};

long long w[500010];
vector<node> a[510];
vector<node> b[500010];
vector<node> eg[510];
long long sz[510];
long long bj[500010];
long long vis[510];
long long g[510][510];
long long f[200010][510];
long long bh, n, m, d, q;
long long cnt = 0;

void dij(long long x){
	cnt++;
	for(long long i = 0; i <= n; i++){
		f[cnt][i] = INF;
		vis[i] = 0;
	}
	priority_queue<node> q;
	for(long long i = 0; i < b[x].size(); i++){
		node v = b[x][i];
		f[cnt][v.x] = v.k;
		q.push(v);
	}
	while(!q.empty()){
		node k = q.top();
		q.pop();
		if(vis[k.x] == 1) continue;
		vis[k.x] = 1;
		for(long long i = 0; i < eg[k.x].size(); i++){
			node v = eg[k.x][i];
			if(f[cnt][k.x] + v.k < f[cnt][v.x]){
				f[cnt][v.x] = f[cnt][k.x] + v.k;
				q.push({v.x, f[cnt][v.x]});
			}
		}
	}
	return;
}

void fy(){
	for(long long k = 1; k <= n; k++){
		for(long long i = 1; i <= n; i++){
			for(long long j = 1; j <= n; j++){
				if(i == j || i == k || j == k) continue;
				if(g[i][k] == INF || g[k][i] == INF) continue;
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> bh >> n >> m >> d >> q;
	for(long long i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(long long i = 1; i <= n; i++){
		cin >> sz[i];
		for(long long j = 1; j <= sz[i]; j++){
			long long x, k;
			cin >> x >> k;
			a[i].push_back({x, k});
			b[x].push_back({i, k});
		}
	}
	for(long long i = 1; i <= n; i++){
		for(long long j = 1; j <= n; j++){
			g[i][j] = INF;
		}
	}
	for(long long i = 1; i <= m; i++){
		for(long long j = 0; j < b[i].size(); j++){
			node u = b[i][j];
			for(long long k = 0; k < b[i].size(); k++){
				if(j == k) continue;
				node v = b[i][k];
				g[u.x][v.x] = min(g[u.x][v.x], u.k + v.k);
				g[v.x][u.x] = min(g[v.x][u.x], u.k + v.k);
			}
		}
	}
	for(long long i = 1; i <= n; i++){
		for(long long j = 1; j <= n; j++){
			if(i == j || g[i][j] == INF) continue;
			eg[i].push_back({j, g[i][j]});
		}
	}
	if(n * n * m * 10 > 100000000){
		fy();
		for(long long i = 1; i <= n; i++){
			g[i][i] = 0;
		}
		for(long long i = 1; i <= q; i++){
			long long x, y;
			cin >> x >> y;
			long long c = INF;
			for(long long j = 0; j < b[x].size(); j++){
				node u = b[x][j];
				for(long long k = 0; k < b[y].size(); k++){
					node v = b[y][k];
					c = min(c, g[u.x][v.x] + u.k + v.k);
				}
			}
			cout << c + w[x] + w[y] << endl;
		}
		return 0;
	}
	for(long long i = 1; i <= m; i++){
		bj[i] = 0;
	}
	for(long long i = 1; i <= q; i++){
		long long x, y;
		cin >> x >> y;
		if(bj[x] == 0){
			dij(x);
			bj[x] = cnt;
		}
		if(bj[y] == 0){
			dij(y);
			bj[y] = cnt;
		}
		long long c = INF;
		for(long long j = 1; j <= n; j++){
			c = min(c, f[bj[x]][j] + f[bj[y]][j]);
		}
		cout << c + w[x] + w[y] << endl;
	}




	return 0;
}
