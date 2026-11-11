#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 5e2 + 5, MAXM = 5e5 + 5;
int c, n, m, d, p, w[MAXM];
vector<pair<int, ll> >a[MAXN + MAXM];
bool v[MAXN + MAXM];
ll ans; 
void bfs(int x, int y) {
	ans = 0;
	memset(v, false, sizeof(v));
	priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;
	q.push({0, x});
	while(q.size() > 0) {
		int t = q.top().first;
		int pos = q.top().second;
		q.pop();
		v[pos] = true;
		if(pos == y) {
			ans = t;
			return;
		}
		for(auto i : a[pos]) {
			if(!v[i.first]) {
				q.push({t + i.second, i.first});
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> p;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		int k; cin >> k;
		for(int j = 1; j <= k; j++) {
			int a1, t; cin >> a1 >> t;
			a[a1].push_back({m + i, t});
			a[m + i].push_back({a1, t});
		}
	}
	while(p--) {
		int x, y; cin >> x >> y;
		bfs(x, y);
		cout << w[x] + ans + w[y] << '\n';
	}
	return 0;
}