#include<bits/stdc++.h>
using namespace std;

int n, k;
long long ans = LLONG_MAX;
long long dist[1000005];
int d[1000005];
vector<int> edge[1000005];

void dfs1(int x, int fa, int step){
	dist[x] = step;
	for(int it : edge[x]){
		if(it == fa) continue;
		dfs1(it, x, step + 1);
	}
}

void f(){
	long long cnt = 0;
	for(int i = 1; i <= n; i++){
		long long minl = INT_MAX;
		for(int j = 1; j <= k; j++){
			minl = min(minl, abs(dist[i] - dist[j]));
		}
		cnt = max(cnt, minl);
	}
	ans = min(ans, cnt);
}

void dfs2(int id, int cnt){
	if(cnt > k){
		f();
		return;
	}
	d[cnt] = 1;
	dfs2(id + 1, cnt + 1);
	d[cnt] = 0;
	dfs2(id + 1, cnt);
}

void solve(){
	cin >> n >> k;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	dfs1(1, 0, 0);
	dfs2(1, 1);
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int c, t;
	cin >> c >> t;
	while(t--) solve();
	
	return 0;
}
