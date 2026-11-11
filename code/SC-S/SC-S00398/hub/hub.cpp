#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5, INF = 1e9;
vector<int> edge[N];
int c, t;
int n, k;
int e[N];
int dist[N];
bool vis1[N], vis2[N], vis3[N];
int ans = INF;
void bfs(int s) {
	queue<int> q;
	q.push(s);
	vis2[s] = 1;
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (int i = 0; i < edge[u].size(); i ++){
			int v = edge[u][i];
			if (!vis2[v]) {
				vis2[v] = 1;
				q.push(v);
			}
		}
	}
}
bool la(int e[]) {
	bfs(e[1]);
	for (int i = 1; i <= k; i ++) {
		if (!vis2[e[i]]) {
			bfs(e[i]);
			break;
		}
	}
	for (int i = 1; i <= k; i ++) {
		if (!vis2[e[i]]) {
			return 0;
		}
	}
	return 1;
}
void dfs(int q, int e[]) {
	if (q == k + 1) {
		if (la(e)) {
			int num = -1;
			for (int qw = 1; qw <= n; qw ++){
				for (int i = 1; i <= n; i ++){
					dist[i] = INF;
					vis3[i] = 0;
				}
				dist[qw] = 0;
				queue<int> q;
				q.push(qw);
				vis3[qw] = 1;
				while (!q.empty()){
					int u = q.front();
					q.pop();
					for (int i = 0; i < edge[u].size(); i ++){
						int v = edge[u][i];
						if (!vis3[v]) {
							vis3[v] = 1;
							dist[v] = dist[u] + 1;
							q.push(v);
						}
					}
				}
				for (int i = 1; i <= n; i ++) num = max(num, dist[i]);
			}
			ans = min(ans, num);
		}
		return;
	}
	for (int i = 1; i <= n; i ++){
		if (!vis1[i]){
			vis1[i] = 1;
			e[q] = i;
			dfs(q + 1, e);
			vis1[i] = 0;
		}
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t --) {
		cin >> n >> k;
		for (int i = 1; i <= n; i ++) {
			int a, b;
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		dfs(1, e);
	}
	return 0;
}