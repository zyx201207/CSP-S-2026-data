#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fir(i, l, r) for(int i = (l); i <= (int) r; i++)
#define fpr(i, r, l) for(int i = (r); i >= (int) l; i--)
const int maxn = 5e5 + 10, maxm = 500 + 10;
int c, n, m, d, q, w[maxn], k[maxn], deg[maxn];
long long dis[maxm][maxm];// u 线路和 v 线路之间的最短距离。
vector <pair <int, int>> con[maxn];// 和 first 车站相连权为 second 
#define endl '\n'
/*
大洋里倒是通过了，
但是跑了 ~600ms
看下会不会过？
饿啊怎么加了快读还是~600ms
诶诶 floyd 怎么通过 johnson 板子的，我忘了
*/
inline int read(){
	char ch = getchar();
	int x = 0;
	while(! isdigit(ch)) ch = getchar();
	while(isdigit(ch)){
//		int num = ch - '0';
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x;
}
signed main(){
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	cin >> c >> n >> m >> d >> q;
//	cout << q << endl;
	c = read(), n = read(), m = read(), d = read(), q = read();
	fir(i, 1, m) w[i] = read();
	fir(i, 1, n){
//		cin >> k[i];
		k[i] = read();
		fir(j, 1, k[i]){
			int a, t;
//			cin >> a >> t;
			a = read(), t = read();
			con[a].push_back({i, t});
//			cout << "connect " << a << " to route: " << i << endl;
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	fir(i, 1, m){//i 车站
		for(int j = 0; j < con[i].size(); j++){//不敢 fir 了哇哇哇！
			int uu = con[i][j].first, _w1 = con[i][j].second;
			for(int k = j + 1; k < con[i].size(); k++){
				int vv = con[i][k].first, _w2 = con[i][k].second;
//				cout << "distance " << uu << ' ' << vv << ' ' << _w1 + _w2 << endl;
				dis[uu][vv] = dis[vv][uu] = min(dis[uu][vv], 1ll * _w1 + _w2);
			}
		}
	}
//	cout << "that" << endl;
	fir(i, 1, n) dis[i][i] = 0;
	fir(i, 1, n){
		fir(k, i + 1, n){
			fir(j, 1, n) dis[i][k] = dis[k][i] = min(dis[i][k], dis[i][j] + dis[j][k]);
//			cout << i << ' ' << k << ' ' << dis[i][k] << endl;
		}
	}
//	cout << q << endl;
	while(q--){
		int u, v;
		long long ans = 0x3f3f3f3f3f3f3f3f;
//		cin >> u >> v;
		u = read(), v = read();
//		cout << "query on " << u << ' ' << v << endl;
//		cout << con[u].size() << ' ' << con[v].size() << endl;
		for(int i = 0; i < con[u].size(); i++){
			for(int j = 0; j < con[v].size(); j++){
				int uu = con[u][i].first, _w1 = con[u][i].second, vv = con[v][j].first, _w2 = con[v][j].second;
//				cout << "node info " << uu << ' ' << vv << endl;
				ans = min(ans, dis[uu][vv] + _w1 + _w2);
			}
		}
		cout << ans + w[u] + w[v] << endl;
//		cout << w[u] + w[v] << endl;
	}
	return 0;
	
}