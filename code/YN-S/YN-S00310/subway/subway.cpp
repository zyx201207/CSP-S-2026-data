#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <queue>
#define IO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int MAXN = 5 * 1e5 + 10;
ll c, n, m, d, q;
ll stepd[MAXN];
bool vis[MAXN];
vector<ll> text[505];

struct node {
	ll station;
	ll stepchange;
};
vector<node> mp[500];

ll bfs(ll &s, ll &e) {
	ll totol = 0;
	queue<ll> q;
	q.push(s);
	while (!q.empty()) {
		ll f = q.front();
		q.pop();
		if (f == s)
			totol += stepd[s];
		if (f == e) {
			totol += stepd[e];
			return totol;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j < mp[i].size(); ++j) {
				if (mp[i][j].station == f) {
					if (j - 1 >= 1 && vis[mp[i][j - 1].station] == 0) {
						q.push(mp[i][j - 1].station);
						//		cout << mp[i][j - 1].station << " ";
						vis[mp[i][j - 1].station] = 1;
					}
					if (j + 1 <= n && vis[mp[i][j + 1].station] == 0) {
						q.push(mp[i][j + 1].station);
						//		cout << mp[i][j + 1].station << " ";
						vis[mp[i][j + 1].station] = 1;
					}
					vector<ll>::iterator it;
					for (it = text[mp[i][j].station].begin(); it < text[mp[i][j].station].end(); ++it) {
						if (*it != i && vis[mp[*it][j].station] == 0) {
							q.push(mp[*it][j].station);
							vis[mp[*it][j].station] = 1;
							totol += mp[i][j].stepchange;
						}
					}
				}
			}
		}
	}

	return 0;
}

ll cal(ll s, ll e) {
	ll ans;
	ans = bfs(s, e);

	return ans;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; ++i) {
		cin >> stepd[i];
	}
	for (ll i = 1; i <= n; ++i) {
		ll k;
		cin >> k;
		for (ll j = 1; j <= k ; ++j) {
			ll stat, stept;
			cin >> stat >> stept;
			mp[i].push_back(node{stat, stept});
			text[stat].push_back(i);
		}
	}
	ll startsta, finalsta;
	for (int i = 1; i <= q; ++i) {
		cin >> startsta >> finalsta;
		cout << cal(startsta, finalsta) << "\n";
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
*/