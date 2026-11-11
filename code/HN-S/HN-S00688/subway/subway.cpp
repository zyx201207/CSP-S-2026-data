#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, q, w[500007], x, y, ans;
struct Node{
	int a, t;
};
vector<Node>l[507];
class A{
	struct Side{
		int j, w;
	};
	struct dij{
		int id, dis;
		bool operator<(const dij& o)const{
			return dis > o.dis;
		}
	};
	vector<Side>g[1007];
	vector<vector<int>>dis;
public:
	A(): dis(507, vector<int>(507, LLONG_MAX >> 1)){
		if(c < 7 || c > 11)
			return;
		for(int i = 1; i <= n; i++)
			if(l[i].size() == 2){
				int u = l[i][0].a, v = l[i][1].a, w = l[i][0].t + l[i][1].t;
				g[u].push_back({v, w}),
				g[v].push_back({u, w});
			}
		for(int i = 1; i <= m; i++){
			priority_queue<dij>q;
			q.push({i, 0});
			dis[i][i] = 0;
			while(q.size()){
				dij t = q.top();
				q.pop();
				for(Side j:g[t.id]){
					if(dis[i][j.j] > t.dis + j.w){
						dis[i][j.j] = t.dis + j.w;
						q.push({j.j, dis[i][j.j]});
					}
				}
			}
		}
	}
	operator bool(){
		return c >= 7 && c <= 11;
	}
	int operator()(int x, int y){
		return w[x] + w[y] + dis[x][y];
	}
};
class B{
	vector<vector<int>>b;
public:
	B(): b(507, vector<int>(507, n + 1)){
		if(c < 12 || c > 19)
			return;
		for(int i = 1; i <= n; i++){
			b[i][i] = 0;
			for(Node j:l[i])
				b[i][j.a] = min(b[i][j.a], 1ll),
				b[j.a][i] = min(b[j.a][i], 1ll);
		}
		for(int k = 1; k <= n; k++)
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++)
					b[i][j] = min(b[i][j], b[i][k] + b[j][k]);
	}
	operator bool(){
		return c >= 12 && c <= 19;
	}
	int operator()(int x, int y){
		return w[x] + w[y] + (b[x][y] + 1) * l[1][0].t * 2;
	}
};
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		l[i].resize(k);
		for(int j = 0; j < k; j++)
			cin >> l[i][j].a >> l[i][j].t;
	}
	A a;
	B b;
	while(q--){
		cin >> x >> y;
		if(a){
			cout << a(x, y) << "\n";
			continue;
		}
		if(b){
			cout << b(x, y) << "\n";
			continue;
		}
		ans = w[x] + w[y];
		cout << ans << "\n";
	}
	return 0;
}
