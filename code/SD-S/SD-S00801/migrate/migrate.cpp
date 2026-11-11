#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> PLL;
const int INF = 0x3f3f3f3f;
const ll INF2 = 0x3f3f3f3f3f3f3f3f;

ll c, T;
ll n, d;
const int N = 2e6 + 10;
const int N2 = 5010;

ll x[N2];
ll dis[N2][N2];
ll cnt[N2][N2];
void dijkstra(ll st) {
	priority_queue<PLL, vector<PLL>, greater<PLL>> q;
	q.push({0, st});
	dis[st][st] = 0;
	
	while (!q.empty()) {
		ll u = q.top().second;
		ll w = q.top().first;
		q.pop();
		
		if (dis[st][u] < w) continue;
		
		for (int v = u+1; v <= n; v++) {
			if (x[v]-x[u] > d) break;
			
			if (dis[st][v] > dis[st][u]+1) {
				dis[st][v] = dis[st][u]+1;
				cnt[st][v] = 1;
				q.push({dis[st][v], v});
			} else if (dis[st][v] == dis[st][u]+1) cnt[st][v]++;
		}
	}
}
void solve1() {
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
	}
	
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cnt[i][j] == 2) {
				ans++;
			}
		}
	}
	cout << ans << '\n';
}

signed main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(),cin.tie(0);

	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		solve1();
	}

	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
