#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q, ans, w[500010], dist[1000010];
vector<pair<int, int> > a[1000010];

void dfs(int s, int t, int v){
	if(s == t){
		ans = min(ans, v);
		return;
	}
	for(auto i : a[s]){
		if(!dist[i.first]){
			dist[i.first] = 1;
			dfs(i.first, t, v + i.second);
			dist[i.first] = 0;
		}
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k, pa = -1;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int A, t;
			cin >> A >> t;
			m++;
			a[m].push_back({A, t});
			a[A].push_back({m, t});
			if(pa != -1){
				a[m].push_back({m - 1, 0});
				a[m - 1].push_back({m, 0});
			}else{
				pa = 0;
			}
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		ans = 2e9;
		dfs(x, y, 0);
		ans += w[x] + w[y];
		cout << ans << "\n";
	}
	return 0;
}
