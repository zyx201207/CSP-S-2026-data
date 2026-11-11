#include<bits/stdc++.h>
#define pii pair<int, int>
#define int long long
#define ios ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int N = 500 + 5;

int k[N];
int c, n, m, d, q;
int w[N * N / 2], a[N][N], t[N][N], dis[N * N / 2];

vector<pii> g[N];

void solve(int x, int y){
	memset(dis, 0x3f, sizeof(dis));
	
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, x});
	dis[x] = 0;
	while(q.size()){
		int u = q.top().second, w = q.top().first;
		q.pop();
		
		
		
		if(dis[u] < w) continue;
		
		
		for(auto [v, ww] : g[u]){
//			cout << dis[v] << ' ' << dis[u] << "\n";
			if(dis[v] > ww + dis[u]){
				dis[v] = dis[u] + ww;
				q.push({dis[u] + ww, v});
//				cout << "pppppppppppppppppppppp";
			}
		}
	}
	cout << dis[y] + w[x] + w[y] << "\n";
}

void solve2(int x, int y){
	memset(dis, 0x3f, sizeof(dis));
	
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, x});
	dis[x] = 0;
	while(q.size()){
		int u = q.top().second, w = q.top().first;
		q.pop();
		
		
		
		if(dis[u] < w) continue;
		
		
		for(auto [v, ww] : g[u]){
//			cout << dis[v] << ' ' << dis[u] << "\n";
			if(dis[v] > ww + dis[u]){
				dis[v] = dis[u] + ww;
				q.push({dis[u] + ww, v});
//				cout << "pppppppppppppppppppppp";
			}
		}
	}
	cout << dis[y] * (t[1][1] + t[1][2]) + w[x] + w[y] << "\n";
}

signed main(){
	ios;
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++) cin >> w[i];
	for(int i = 1;i <= n;i ++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j ++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	
	if(c >= 7 && c <= 11){
		for(int i = 1;i <= n;i ++){
			int u = a[i][1], v = a[i][2], w = t[i][1] + t[i][2];
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
		while(q --){
			int x, y;cin >> x >> y;
			solve(x, y);
		}
	}else if(12 <= c && c <= 19){
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= k[i];j ++){
				int u = a[i][j], v = a[i][j];
				g[u].push_back({v, 1});
				g[v].push_back({u, 1});
			}
		}
		while(q --){
			int x, y;cin >> x >> y;
			solve2(x, y);
		}
	}
	
	return 0;
}