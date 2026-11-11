#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int c, t, n, k, dep[N];

vector<int> v[N];

void dfs(int x, int fa, int d){
	dep[x] = min(dep[x], d);
	for(int i : v[x])
		if(i != fa)
			dfs(i, x, d + 1);
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	for(; t; t--){
		cin >> n >> k;
		for(int i = 0; i < n; i++)
			v[i].clear();
		for(int i = 1, x, y; i < n; i++){
			cin >> x >> y;
			x--, y--;
			v[x].push_back(y), v[y].push_back(x);
		}
		int ans = n;
		for(int i = 1; i < (1 << n); i++){
			if(__builtin_popcount(i) > k)continue;
			int ct = 0;
			for(int j = 0; j < n; j++)
				if((i >> j) & 1)
					for(int k : v[j])
						ct += ((i >> k) & 1);
			ct /= 2;
			if(ct < __builtin_popcount(i) - 2)continue;
			fill(&dep[0], &dep[n] + 1, n + 1);
			for(int j = 0; j < n; j++)
				if((i >> j) & 1)
					dfs(j, -1, 0);
			int mx = 0;
			for(int j = 0; j < n; j++)
				mx = max(mx, dep[j]);
			ans = min(ans, mx);
		}
		cout << ans << '\n';
	}
	return 0;
}