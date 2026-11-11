#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 4e5 + 11;

int c, n, m, d , q, x, y, w[N], a[511][N], t[511][N], k[511];
vector <int> v[N];///铁路路线 
bool f[N];
ll ans;

void dfs(int u, ll sum,int y,bool ff) {
	if(u == y) {///u:当前所在编号 mc:第mc个路线 f:是否访问过 
		ans = min(ans,sum);
		return ;
	}
	for(int i = 0; i < v[u].size(); i++) {
		int mc = v[u][i];
		if(f[mc]) continue;
		f[mc] = 1;
		if(u == a[mc][1]) {
//			cout << 1;
//			f[a[mc][2]] = 1;
			dfs(a[mc][2],sum+t[mc][2]+t[mc][1],y,0);
//			f[a[mc][2]] = 0;
		}
		else {
//			cout << 2;
//			f[a[mc][1]] = 1;
			dfs(a[mc][1],sum+t[mc][2]+t[mc][1],y,1);
//			f[a[mc][1]] = 0;
		}
		f[mc] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			if(k[i] != 1) v[a[i][j]].push_back(i);
		}
	}
	while(q--) {
		ans = 1e9+7;
		cin >> x >> y;
		if(x > y) swap(x,y);
		dfs(x,0ll,y,-1);
		cout << ans+w[x]+w[y] << '\n';
	}
	return 0;///地铁口----站厅----站台
}
/*
i:	1	2	3	4	5
w:	4   1   9   2   5
	-----      --
t1	5   7		6
		------     --
t2		3	4		7*/
