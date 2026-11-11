#include<bits/stdc++.h>
using namespace std;

const int M = 5e5 + 10;
const int N = 500 + 5;
const int D = 20 + 1;
const long long INF = 5e17;

long long c, n, m, d, q;
int w[M];
vector<int> sta[M];
vector<int> adr[M];
long long dis[N][N];
long long crt[N][N];
vector<int> edge[N];
int Myqueue[N * N], l, r;
bool inqueue[N];
long long ans = 0;



int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++){
		int k;
		scanf("%d", &k);
		for(int j = 0; j < k; j ++){
			int u, t;
			scanf("%d %d", &u, &t);
			adr[u].push_back(i);
			sta[u].push_back(t);
		}
	}
	
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			dis[i][j] = INF;
			crt[i][j] = INF;
		}
	}
	
	
	for(int i = 1; i <= m; i ++){
		for(int j = 0; j < sta[i].size(); j ++){
			for(int k = j + 1; k < sta[i].size(); k ++){
				int u = adr[i][j], v = adr[i][k];
				dis[u][v] = min(dis[u][v], (long long)(sta[i][j] + sta[i][k]));
				dis[v][u] = min(dis[v][u], (long long)(sta[i][j] + sta[i][k]));
			}
		}
	}
	
	
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			if(i == j) continue;
			if(dis[i][j] == INF) continue;
			edge[i].push_back(j);
		}
	}
	
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++) inqueue[j] = false;
		
		l = 0; r = 0;
		Myqueue[r ++] = i;
		crt[i][i] = 0;
		
		
		while(l < r){
			int u = Myqueue[l ++];
			for(auto v : edge[u]){
				if(crt[v][i] > crt[u][i] + dis[u][v]){
					if(!inqueue[v]) Myqueue[r ++] = v;
					inqueue[v] = true;
					crt[v][i] = crt[u][i] + dis[u][v];
				}
			}
		}
	}
	
	for(; q; q --){
		int x, y;
		cin >> x >> y;
		
		ans = INF;
		
		for(int i = 0; i < sta[x].size(); i ++){
			for(int j = 0; j < sta[x].size(); j ++){
				int u = adr[x][i], v = adr[y][j];
				ans = min(ans, w[x] + w[y] + crt[u][v] + sta[x][i] + sta[y][j]);
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}
