/*
题目比较难读懂，
实际上是在说一个简单的最短路问题。

思考：w是必须加的，所以不用考虑w。
	 把站台与地铁站看成一堆点，通道看成有权值的边，那么这下这张图就清晰了：
	 其实就是个模板的多元最短路。 
	 这里用Floyd. 
	 
Floyd:
对于每条边进行松弛操作 
for(int k=1; k<=n; k++){
	for(int i=1; i<=k; i++){
		for(int j=1; j<=k; j++){
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
}

dist[i][j] = dist[i][k] + dist[k][j]
*/ 
#include<bits/stdc++.h>
#define N 5009
#define M 500009
#define INF 1 << 28
using namespace std;

struct edge{
	int to;
	int w;
};
vector<edge> G[N];
int n, m, dist[N][N];

void mindist(){
	for(int i=1; i<=n+m; i++)
		for(int j=1; j<=n+m; j++)
			dist[i][j] = (i == j) ? 0 : INF; //初始化 
	
	for(int i=1; i<=n+m; i++){
		int t = G[i].size();
		for(int j=0; j<t; j++){
			dist[i][G[i][j].to] = G[i][j].w; //读入边权 
		}		
	}
	
	for(int k=1; k<=n+m; k++)
		for(int i=1; i<=n+m; i++)
			for(int j=1; j<=n+m; j++){
				if(dist[i][k] == INF or dist[k][j] == INF) continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
}

int W[M];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++) cin >> W[i];
	for(int i=1; i<=n; i++){
		int k;
		cin >> k;
		for(int j=1; j<=k; j++){
			int a, t;
			cin >> a >> t;
			G[a].push_back({i+m, t});
			G[i+m].push_back({a, t});
		} 
	}
	
	mindist();
	
	for(int i=1; i<=q; i++){
		int x, y;
		cin >> x >> y;
		cout << dist[x][y] + W[x] + W[y] << '\n';
	}
	return 0;
}
