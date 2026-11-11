#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(I, A, B) for(int I = (A); I <= (B); I++)
#define den(I, A, B) for(int I = (A); I >= (B); I--)
#define pii pair<int, int> 
#define fr first
#define sc second
#define int long long
/*
先预处理出来每个车到每个车的最短
对于每个询问 枚举两边的车 求出最短路 取 min 即可 
可以获得 56 pts 
tim : 14:58 待完成 
*/
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 505;
const int M = 5e5 + 5;
int g[N][N];
int w[M];
vector<pii> dt[M];
vector<pii> zt[M];
signed main(){
	ios::sync_with_stdio(0);
	cout.tie(0), cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
//	cout << n << endl;
	rep(i, 1, m) cin >> w[i];
	rep(u, 1, n){
		int k;
		cin >> k;
		rep(j, 1, k){
			int v, w;
			cin >> v >> w;
			dt[u].push_back({w, v});
			zt[v].push_back({w, u});
		}
	}
	rep(i, 1, n){
		rep(j, 1, n) g[i][j] = INF;
		g[i][i] = 0;
	}
	rep(u, 1, n){
		for(auto p : dt[u]){
			int w1 = p.fr, mid = p.sc;
			for(auto p2 : zt[mid]){
				int w2 = p2.fr, v = p2.sc;
				int w=  w1 + w2;
//				cout << u << " "<< mid << " " << v << " " << w1 << " " << w2 << endl; 
				g[u][v] = min(g[u][v], w);
			}
		}
	}
	rep(k, 1, n){
		rep(i, 1, n){
			rep(j, 1, n){
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
//	rep(i, 1, n){
//		rep(j, 1, n) cout << g[i][j] << " ";
//		cout << endl;
//	}
//	cout << INF << endl;
	while(q--){
		int u, v;
		cin >> u >> v;
		int ans = INF;
		for(auto p1 : zt[u]){
			int w1 = p1.fr, i = p1.sc;
			for(auto p2 : zt[v]){
				int w2 = p2.fr, j = p2.sc;
				int cur = w1 + w2 + g[i][j];
				ans = min(ans, cur);
			}
		}
		ans += w[u] + w[v];
		cout << ans << endl;
	}
	return 0;
}
/*
fc  subway3.out subway3.ans
*/
