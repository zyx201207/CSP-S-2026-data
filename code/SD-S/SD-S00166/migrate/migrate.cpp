#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using pii = pair<int, int>;

const int mod = 998244353;

void bfs(int s, const vector<vector<int> > &ve, vector<i64> &dis, vector<i64> &vis, vector<i64> &cnt) {
	queue<int> q;
	dis[s] = 0;
	q.push(s);
	while (q.size()) {
		int u = q.front();
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int v : ve[u]) {
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				cnt[v] = 1;
				q.push(v);
			}
			else if (dis[v] == dis[u] + 1) {
				cnt[v] ++;
			}
		}
	}
}

void solve(int c) {
	int n;
	i64 d;
	cin >> n >> d;
	
	vector<i64> a(n + 1);
	for (int i = 1; i <= n; i ++) cin >> a[i];
	
	if (c <= 10) {
		
		set<pii> ans;
		vector<vector<int> > ve(n + 1);
		
		for (int i = 1; i <= n; i ++) {
			int is = 1;
			int k1 = lower_bound(a.begin() + i + 1, a.end(), a[i] + d) - a.begin();
			if (k1 == n + 1 || a[k1] > a[i] + d) is = 0;
			if (is) {
				for (int j = i + 1; j <= k1; j ++) ve[i].push_back(j);
			}
			if (i > 1) {
				int k2 = lower_bound(a.begin() + 1, a.begin() + i - 1, a[i] - d) - a.begin();
				if (k2 == i || a[k2] < a[i] - d) continue;
				for (int j = k2; j < i; j ++) ve[i].push_back(j);
			}
		} 
		for (int s = 1; s <= n; s ++) {
			vector<i64> dis(n + 1, 1e9), vis(n + 1, 0), cnt(n + 1, 1);
			bfs(s, ve, dis, vis, cnt);
			for (int i = 1; i <= n; i ++) {
//				cout << dis[i] << ' ' ;
				if (dis[i] == 2 && cnt[i] == 2) {
					if (i < s) ans.insert({i, s});
					else ans.insert({s, i});
				}
			}
//			cout << '\n';
		}
		cout << ans.size() << '\n';
	}
	else if (c == 11 || c == 12) {
		
	}
	else if (c == 13 || c == 14) {
		
	}
	else if (c >= 15 || c <= 18) {
		
	}
	else if (c > 18) {
		cout << 0 << '\n' ;
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
	
	int c, T;
  	cin >> c >> T;
	while (T --) {
		  solve(c);
	}
	
	return 0;
}

/*
考砸了
我本就很废 
 我对不起所有人 
*/

