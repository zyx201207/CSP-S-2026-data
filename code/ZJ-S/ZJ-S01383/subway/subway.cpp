#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, d, q, w[500005], x, y, sub[505][25];
vector<int> v[500005];
inline void dfs(){
	
}signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1, k; i <= n; i++){
		cin >> k;
		while(k--){
			cin >> x >> y;
			sub[i][x] = y;
			v[i].push_back(x);
		}
	}while(q--){
		cin >> x >> y;
	}
	return 0;
}
