#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 5e5+10;
int c, n, m, d, q;
int w[N];
vector<pair<int, ll> > e[505]; 

struct link{
	int k;
	vector<int> a, t;
}lk[505];
struct station{
	vector<int> l, t;
}st[N];

struct node{
	ll d; int u;
	bool operator< (const node &other) const {
		return u < other.u;
	}
};
ll dist[505];
void dijkstra(int s) {
	memset(dist, 0x3f, sizeof dist);
	priority_queue<node> q;
	dist[s] = 0;
	q.push({0, s});
	while (!q.empty()) {
		node tt = q.top(); q.pop();
		ll d = tt.d;
		int u = tt.u;
		if (d != dist[u]) continue;
		
		for (int i = 0; i < e[u].size(); i++) {
			pair<int, ll> tv = e[u][i];
			int v = tv.first;
			ll w = tv.second;
			if (dist[u] + w <= dist[v]) {
				dist[v] = dist[u] + w;
				q.push({dist[v], v});
			}
		} 
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> lk[i].k;
		lk[i].a.resize(lk[i].k+1);
		lk[i].t.resize(lk[i].k+1);
		for (int j = 1; j <= lk[i].k; j++) {
			cin >> lk[i].a[j] >> lk[i].t[j];
			st[lk[i].a[j]].l.pb(i);
			st[lk[i].a[j]].t.pb(lk[i].t[j]);
		}
	}
	
	for (int i = 1; i <= m; i++) {
		if (st[i].l.size() == 1) continue;
		for (int j = 0; j < st[i].l.size(); j++) {
			for (int k = j+1; k < st[i].l.size(); k++) {
//				printf("j %d k %d e[%d] = %d %d\n", j, k, st[i].l[j], st[i].l[k], st[i].t[j] + st[i].t[k]);
				e[st[i].l[j]].pb({st[i].l[k], st[i].t[j] + st[i].t[k]});
				e[st[i].l[k]].pb({st[i].l[j], st[i].t[j] + st[i].t[k]});
			}
		}
	}
	
	while (q--) {
		int x, y;
		cin >> x >> y;
		ll ans = 0x3f3f3f3f3f3f3f3f;
		for (int j = 0; j < st[x].l.size(); j++) {
			dijkstra(st[x].l[j]);
			ll mn = 0x3f3f3f3f3f3f3f3f;
			for (int k = 0; k < st[y].l.size(); k++) {
				mn = min(mn, dist[st[y].l[k]] + w[y] + st[y].t[k]);
			}
			
			ans = min(mn + w[x] + st[x].t[j], ans);
		}
		cout << ans << '\n';
	}
	

	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7

*/
