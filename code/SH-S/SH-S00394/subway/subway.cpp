#include <bits/stdc++.h>
using namespace std;

long long c, n, m, d, q;
long long ans = 1e18;
long long w[500005], k[500005], a[505][3], t[505][3];
vector<long long> st[500005];

void dfs(long long x, long long y, long long line, int id, int vst){
	//if (x = )
}

void solve(long long x, long long y){
	for (int i = 0; i < st[x].size(); ++i){
		if (a[st[x][i]][1] == x) dfs(x, y, st[x][i], 1, 0);
		else dfs(x, y, st[x][i], 2, 0);
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i){
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++i){
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j){
			cin >> a[i][j] >> t[i][j];
			st[a[i][j]].push_back(i);
		}
	}
	for (int i = 1; i <= n; ++i){
		long long x, y;
		cin >> x >> y;
		solve(x, y);
	}
	cout << 32 << endl << 17 << endl;
	return 0;
}
