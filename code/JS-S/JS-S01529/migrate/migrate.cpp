#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bfs(const vector<vector<int>>& g, int s){
	vector<int> dis(g.size(), INT_MAX), cnt(g.size());
	queue<int> q;
	dis[s] = 0;
	q.push(s);

	while(!q.empty()){
		int x = q.front();
		q.pop();

		for(int p : g[x]){
			int nd = dis[x] + 1;
			if(nd <= dis[p]){
				if(++cnt[p] <= 3){
					dis[p] = nd;
					q.push(p);
				}
			}
		}
	}

	ll res = 0;
	for(int i = 1; i < g.size(); i++)
		res += cnt[i] == 2;

	return res;
}

void solve(){
	int n;
	ll d;
	cin >> n >> d;
	vector<ll> v(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> v[i];

	vector<vector<int>> g(n + 1);
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(v[j] - v[i] <= d)
				g[i].push_back(j), g[j].push_back(i);
		}
	}

	ll res = 0;
	for(int i = 1; i <= n; i++)
		res += bfs(g, i);

	cout << res / 2 << '\n';
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	int c, t;
	cin >> c >> t;

	while(t--)
		solve();

	return 0;
}