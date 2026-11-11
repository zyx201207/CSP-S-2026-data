#include<bits/stdc++.h>
using namespace std;
int g, t, n, d[2000010], c[2000010], ans;
long long p, a[2000010];
vector<int> e[2000010];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
void dij(int s) {
	memset(d, 0x3f, sizeof(d));
	memset(c, 0, sizeof(c));
	d[s] = 0;
	c[s] = 1;
	q.push({0, s});
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		for(auto v : e[u]) {
			if(d[u] + 1 < d[v]) {
				d[v] = d[u] + 1;
				c[v] = c[u];
				q.push({d[v], v});
			}
			else if(d[u] + 1 == d[v])
				c[v] += c[u];
		}
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> g >> t;
	while(t--) {
		cin >> n >> p;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++)
			e[i].clear();
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(j != i && a[i] - a[j] <= p)
					e[i].push_back(j);
		ans = 0;
		for(int i = 1; i <= n; i++) {
			dij(i);
			for(int j = 1; j <= n; j++)
				if(c[j] == 2)
					ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}