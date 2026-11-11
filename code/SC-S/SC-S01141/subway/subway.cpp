#include<bits/stdc++.h>//32+pts
typedef long long ll;
using namespace std;
const int maxm = 5e5 + 5, mod = 998244353;
const ll inf = 1e18;
int C;
ll n, m, d, q, dis[maxm + 500], w[maxm];
vector<pair<ll, ll>> g[maxm + 500];
struct node{
	ll u, dis;
	bool operator<(const node &others)const{
		return dis > others.dis;
	}
};
void dij(ll s, ll t){
	for (int i = 1; i <= n + m; i++) dis[i] = inf;
	dis[s] = 0;
	priority_queue<node>q;
	q.push({s, 0});
	while (!q.empty()){
		auto now = q.top();
		q.pop();
		ll u = now.u, dis_u = now.dis;
		if (u == t) return;
		if (dis_u > dis[u]) continue;
		for (auto i : g[u]){
			ll v = i.first, w = i.second;
			if (dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				q.push({v, dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> C >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++){
		ll u = i + m, k;
		cin >> k;
		for (int j = 1; j <= k; j++){
			ll v, w;
			cin >> v >> w;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
	}
	while (q--){
		ll x, y;
		cin >> x >> y;
		dij(x, y);
		cout << dis[y] + w[x] + w[y] << '\n';
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