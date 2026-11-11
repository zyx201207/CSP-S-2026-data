#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int c, t, n, K, len, flag;
int ct[N], mxdep[N], vis[N], f[N], dep[N], v2[N];

vector<int> v[N];

void dfs(int x, int fa){
	mxdep[x] = 0, f[x] = fa;
	for(int i : v[x])
		if(i != fa)
			vis[i] = (!fa ? i : vis[x]), dfs(i, x), mxdep[x] = max(mxdep[x], mxdep[i] + 1), ct[x] += ct[i];
	if(mxdep[x] >= len)ct[x]++;
	// cout << '#' << x << ' ' << fa << ' ' << ct[x] << ' ' << mxdep[x] << '\n';
}

void dfs2(int x, int d){
	dep[x] = min(dep[x], d);
	v2[x] = 1;
	for(int i : v[x])
		if(!v2[i])
			dfs2(i, d + 1);
}

void check(){
	flag = 0;
	// cout << len << '\n';
	for(int i = 1; i <= n && !flag; i++){
		fill(&ct[0], &ct[n] + 1, 0);
		fill(&mxdep[0], &mxdep[n] + 1, 0);
		dfs(i, 0);
		flag |= (ct[i] <= K);
		// if(ct[i] <= K)cout << '%' << i << ' ' << ct[i] << ' ' << mxdep[3] << '\n';
		// cout << i << '%' << ct[i] << ' ' << mxdep[i] << '\n';
		for(int j = 1; j <= n; j++){
			for(int k = j + 1; k <= n; k++){
				// cout << i << ' ' << j << ' ' << k << ' ' << vis[j] << ' ' << vis[k] << ' ' << ct[j] << ' ' << ct[k] << '\n';
				if(j != i && k != i && vis[j] != vis[k] && max(1, ct[j]) + max(1, ct[k]) <= K){
					fill(&dep[0], &dep[n] + 1, n + 1);
					fill(&v2[0], &v2[n] + 1, 0);
					v2[j] = v2[k] = 1;
					dfs2(f[j], 1);
					fill(&v2[0], &v2[n] + 1, 0);
					v2[j] = v2[k] = 1;
					dfs2(f[k], 1);
					int flag2 = 1;
					for(int k2 = 1; k2 <= n; k2++)
						flag2 &= (dep[k2] == n + 1 || dep[k2] <= len);
					flag |= flag2;
					// if(flag2)cout << i << ' ' << j << ' ' << k << ' ' << ct[j] << ' ' << ct[k] << '\n';
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	for(; t; t--){
		cin >> n >> K;
		for(int i = 0; i < n; i++)
			v[i].clear();
		for(int i = 1, x, y; i < n; i++){
			cin >> x >> y;
			v[x].push_back(y), v[y].push_back(x);
		}
		int l = 1, r = n;
		while(l < r){
			int mid = (l + r) >> 1;
			len = mid, check();
			if(flag)r = mid;
			else l = mid + 1;
		}
		cout << l << '\n';
	}
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5

1

*/