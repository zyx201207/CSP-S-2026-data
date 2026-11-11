#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int SIZE = 1e6 + 5, inf = 1e18;
int c, n, k, ans;
vector <int> e[SIZE];
bool b[15], vis[15];
queue <int> q;
void bfs(int start){
	while (!q.empty())q.pop();
	q.push(start);
	vis[start] = 1;
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		for (int i : e[cur]){
			if (!vis[i] && b[i]){
				vis[i] = 1;
				q.push(i);
			}
		}
	}
	return;
}
int calc (int start){
	memset(vis, 0, sizeof vis);
	queue <int> t;
	while (!q.empty()) q.pop();
	q.push(start), t.push(0);
	vis[start] = 1;
	while (!q.empty()){
		int cur = q.front(), curt = t.front();
		q.pop(), t.pop();
		if (b[cur]) return curt;
		for (int i : e[cur]){
			if (!vis[i]){
				vis[i] = 1;
				q.push(i);
				t.push(curt + 1);
			}
		}
	}
}
void check (){
	int flg = 0;
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i++){
		if (b[i] && !vis[i]){
			if (flg == 2)return;
			else bfs(i), flg ++;
		}
	}
	int _ans = 0;
	for (int i = 1; i <= n; i++){
		_ans = max(_ans, calc(i));
	}
	ans = min(ans, _ans);
}
void dfs (int cur, int cnt){
	if (cnt == k) {
		check();
		return;
	}
	if (cur == n + 1)return;
	for (int i = cur + 1; i <= n; i++){
		b[i] = 1;
		dfs(i, cnt + 1);
		b[i] = 0;
	}
	return;
}
void _main() {
	ans = inf;
	cin >> n >> k;
	for (int i = 1; i < n; i++)e[i].clear();
	for (int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	} 
	dfs(0, 0);
	cout << ans << "\n";
	return;
} 
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> c >> t;
	while (t--){
		_main();
	}
}
