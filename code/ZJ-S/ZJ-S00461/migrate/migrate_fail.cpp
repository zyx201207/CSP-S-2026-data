#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5010;
int n, d, x[maxn], f[maxn], in[maxn], dep[maxn];
queue <int> q;
vector <int> G[maxn];
void dfs(int x) {
	for(int y : G[x]) {
		f[y] += f[x];
		dfs(y);
	}
}
void solve1() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for(int i = 1; i <= n; i++) G[i].clear(), in[i] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(x[j] - x[i] <= d) G[i].push_back(j), in[j]++;
		}
	}
	while(!q.empty()) q.pop();
	for(int i = 1; i <= n; i++) {
		if(!in[i]) q.push(i), dep[i] = 0;
		else dep[i] = 1e18;
	}
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(int y : G[x]) {
			in[y]--;
			dep[y] = min(dep[y], dep[x] + 1);
			if(!in[y]) q.push(y);
		}
	}
	for(int i = 1; i <= n; i++) G[i].clear();
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(x[j] - x[i] <= d) {
				if(dep[i] == dep[j] - 1) {
					G[i].push_back(j);
					cout << i << " " << j << "\n";
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) f[j] = 0; 
		f[i] = 1;
		while(!q.empty()) q.pop();
		q.push(i);
		while(!q.empty()) {
			int x = q.front(); q.pop();
			for(int y : G[x]) {
				f[y] += f[x];
				q.push(y);
			}
		}
		for(int j = 1; j <= n; j++) if(f[j] == 2) {
			cout << i << " " << j << "\n";
			ans++;
		}
	}
	cout << ans << "\n";
}
signed main() {
//	freopen("migrate1.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, T;
	cin >> c >> T;
	if(c <= 10) {
		while(T--) solve1();
	}
	return 0;
}
/*
0 1
5 2
1 2 3 4 5
*/
