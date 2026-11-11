#include <bits/stdc++.h>
using namespace std;

const int N = 500 + 5, M = 5e5 + 5;

long long c, n, m, d, q, w[M], k[N], x, y, ans, f1[M], f2[M], p;
vector<long long> a[N];
vector<long long> t[N];
vector<long long> fa[M];

void dfs(long long s, long long res){
	if (s == y){
		ans = min(ans, res);
		return;
	}
	
	f1[s] = 1;
	for (auto i : fa[s]){
		if (f2[i] == 1) continue;
		f2[i] = 1;
		for (int j = 0; j < k[i]; j ++ ){
			if (a[i][j] == s) p = j;
		}
		for (int j = 0; j < k[i]; j ++ ){
			if (f1[a[i][j]] == 1) continue;
			dfs(a[i][j], res + t[i][j] + t[i][p]);
		}
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++ ){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i ++ ){
		cin >> k[i];
		for (int j = 1; j <= k[i]; j ++ ){
			cin >> x >> y;
			fa[x].push_back(i);
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	
	while (q -- ){
		cin >> x >> y;
		ans = INT_MAX;
		for (int i = 1; i <= m; i ++ ) f1[i] = f2[i] = 0;
		
		dfs(x, 0);
		cout << ans + w[x] + w[y] << '\n';
	}
	
	return 0;
}