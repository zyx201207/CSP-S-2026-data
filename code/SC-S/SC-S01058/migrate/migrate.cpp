#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int c, T, n, d, x[N], ans, cnt, mi;

inline void dfs(int now, int sum, int v){
	if(now == v){
		if(sum < mi) mi = sum, cnt = 1;
		else if(sum == mi) cnt++;
		return ;
	}
	for(int i = now + 1; i <= n; i++){
		if(x[i] - x[now] > d) break;
		dfs(i, sum + 1, v);
	}
}

inline bool check(int u, int v){
	cnt = 0; mi = 1e18;
	dfs(u, 0, v);
	if(cnt == 2) return 1;
	return 0;
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while(T--){
		ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(check(i, j)) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

//@DanseSolo 姐姐可爱喵 