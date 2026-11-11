#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;

const int N = 6e5 + 10, D = 520;
int c, n, m, d, q;
ll w[N], pl[N], t[N][25], sub[N][25];
int num, id;
ll Time;
ll trans[D][D], trans_cost[D][D];
priority_queue <pll, vector<pll>, greater<pll> > pq;
bool vis[D];
int x, y;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> num;
		for (int j = 1; j <= num; j++) {
			cin >> id >> Time;
			pl[id]++;
			t[id][pl[id]] = Time;
			sub[id][pl[id]] = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) trans[i][j] = 2e18;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= pl[i]; j++) {
			for (int k = 1; k <= pl[i]; k++) {
				trans[sub[i][j]][sub[i][k]] = min(trans[sub[i][j]][sub[i][k]], t[i][j] + t[i][k]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		while (!pq.empty()) pq.pop();
		memset(vis, 0, sizeof(vis));
		
		pq.push(make_pair(0, i));
		while (!pq.empty()) {
			pll k = pq.top();
			pq.pop();
			if (vis[k.second]) continue;
			vis[k.second] = 1;
			trans_cost[i][k.second] = k.first;
			for (int j = 1; j <= n; j++) {
				if ((j == k.second or vis[j]) and trans[k.second][j] != 2e18) continue;
				pq.push(make_pair(k.first + trans[k.second][j], j));
			}
		}
	}
	
	while (q--) {
		cin >> x >> y;
		ll best = 2e18;
		for (int i = 1; i <= pl[x]; i++) {
			for (int j = 1; j <= pl[y]; j++) best = min(best, t[x][i] + t[y][j] + trans_cost[sub[x][i]][sub[y][j]]);		
		}
		cout << best + w[x] + w[y] << '\n';
	}
	
	return 0;
}
