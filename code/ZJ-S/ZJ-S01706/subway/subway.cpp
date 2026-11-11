#include <bits/stdc++.h>
#define MAXN 502
#define MAXM 500002
#define MAXD 22
#define MAXQ 100002
using namespace std;
typedef long long ll;
struct WayNode {
	int a;
	ll t;
};
// hall -> outside
ll hod[MAXM];
// way len & record begin
int wlen[MAXN], beg[MAXN];
WayNode arr[MAXM];
// way -> way
ll dis[MAXN][MAXN];
// station -> way
struct StaToWay {
	int to, next;
	ll t;
};
StaToWay stw[MAXD*MAXM];
int sta_head[MAXM], sta_head_cnt = 1;
void add_sta_to_way(int sta, int way, ll t) {
	stw[sta_head_cnt] = { way, sta_head[sta], t };
	sta_head[sta] = sta_head_cnt++;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, n, m, d, q, u, v;
	// n: way
	// m: station
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) 
		cin >> hod[i];
	for (int i = 1; i <= n; i++) {
		cin >> wlen[i];
		beg[i] = beg[i - 1] + wlen[i - 1];
		for (int j = 1; j <= wlen[i]; j++) {
			cin >> arr[beg[i] + j].a >> arr[beg[i] + j].t;
			add_sta_to_way(arr[beg[i] + j].a, i, arr[beg[i] + j].t);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = -1;
		}
	}
	for (int from = 1; from <= n; from++) {
		dis[from][from] = 0;
		for (int j = beg[from] + 1; j <= beg[from] + wlen[from]; j++) {
			for (int k = sta_head[arr[j].a]; k; k = stw[k].next) {
				int to = stw[k].to;
				ll w = stw[k].t;
				if (to != from) {
					if (dis[from][to] == -1 || dis[from][to] > arr[j].t + w) {
						dis[from][to] = arr[j].t + w;
					}
					dis[to][from] = dis[from][to];
				}
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dis[i][k] != -1 && dis[j][k] != -1) {
					if (dis[i][j] == -1 || dis[i][j] > dis[i][k] + dis[k][j]) {
						dis[i][j] = dis[i][k] + dis[k][j];
					}
				}
			}
		}
	}
	while (q--) {
		cin >> u >> v;
		ll ans = LLONG_MAX;
		for (int i = sta_head[u]; i; i = stw[i].next) {
			for (int j = sta_head[v]; j; j = stw[j].next) {
				int from = stw[i].to;
				int to = stw[j].to;
				ans = min(ans, dis[from][to] + stw[i].t + stw[j].t);
			}
		}
		cout << (ans + hod[u] + hod[v]) << "\n";
	}
	return 0;
}
