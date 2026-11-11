#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 550;
const int M = 5e5+5;

int c, n, m, d, q;
int w[M];
int k[N];
int a[N][M];
int t[N][M];

vecter<pair<int, int>> g[N*M];
void add(int u, int v, int w){
	g[u].push_back({v, w});
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i]; // 地铁口走到站厅需要的时间
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i]; // 第 i 条线路经过的地铁站数
		for(int j = 1; j <= k; j++){
			cin >> a[i][j]; // 第 i 条线路经过的第 j 个地铁站
			
			int x = a[i][j-1], y = a[i][j];
			add(x, y, 0);
			add(y, x, 0);
			
			cin >> t[i][j]; // 站厅走到站台需要的时间
			
			
			
		}
	}
	
	for(int i = 1; i <= m; i++){
		
	}
	
	while(q--){
		int x, y; cin >> x >> y;
		int ans = 0;
		ans += w[x]+w[y];
		
		
	}
	
	return 0;
}
