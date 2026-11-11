#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int c, t, n, k, dis[maxn];
vector<int> g[maxn];
bool visited[maxn];
void dfs(int x, int w) {
	visited[x] = true;
	for(int y : g[x]) {
		if(!visited[y] && (w >> (y-1) & 1)) {
			dfs(y, w);
		}
	}
}
bool check(int w) {
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
	       	visited[i] = false;
		if(w >> (i-1) & 1) cnt++;
	}
	//cerr << "check: " << w << ", cnt1 =  " << cnt << endl;
	if(cnt != k) return false;
	cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(!visited[i] && (w >> (i-1) & 1)) {
			cnt++;
			dfs(i, w);
		}
	}
	//cerr << "cnt2 = " << cnt << endl;
	return cnt <= 2;
}
int bfs(int w) {
	queue<int> q;
	for(int i = 1; i <= n; i++) {
		visited[i] = false;
		dis[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		if(w >> (i-1) & 1) {
			visited[i] = true;
			dis[i] = 0;
			q.push(i);
		}
	}
	int res = 0;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		res = max(res, dis[x]);
		for(int y : g[x]) {
			if(!visited[y]) {
				visited[y] = true;
				dis[y] = dis[x] + 1;
				q.push(y);
			}
		}
	}
	return res;
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 1; i <= n; i++) g[i].clear();
		for(int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans = n;
		for(int w = 1; w < (1 << n); w++) {
			if(check(w)) {
				int tmp = bfs(w);
				//cerr << w << " " << tmp << endl;
				ans = min(ans, tmp);
			}
		}
		cout << ans << endl;
	}			
	return 0;
}
