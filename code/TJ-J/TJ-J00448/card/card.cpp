#include <bits/stdc++.h>

#define int long long 

using namespace std;

const int N = 1e6 + 10;
int n, m;
int a[N], goal[N];
int mp[N], last[N];
vector<int> g[N];

void DFS(int u) {
	goal[u] = mp[u];
	for(int i = 0; i < g[u].size(); i ++ ) {
		int v = g[u][i];
		DFS(v);
		goal[u] += goal[v];
	}
}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ ) {
		cin >> a[i];
		mp[a[i]] ++ ;
	}
	
	int root = -1;
	for(int i = n; i >= 1; i -- ) {
		if(!last[a[i]]) {
			if(i == n) root = a[i];
			else g[a[i + 1]].push_back(a[i]);
		}
		last[a[i]] = i;
	}
	
	DFS(root);
	for(int i = 1; i <= m; i ++ ) 
		cout << goal[i] << " ";
}

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int t; t = 1;
	while(t -- ) solve();
	return 0;
}
