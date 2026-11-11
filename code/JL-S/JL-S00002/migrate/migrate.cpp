#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, d;
int x[22];
bool vis[22];
int cnt[22];
int minn;
int Abs(int x){
	if (x > 0)return x;
	else return -x;
}
void dfs(int u, int des, int step){
	if (u == des){
		minn = min(step, minn);
		cnt[step]++;
		return;
	}
	if (step > minn)return;
	if (step > n)return;
	for (int i = 1; i <= n; i++){
		if (vis[i])continue;
		if (Abs(x[i] - x[u]) > d)continue;
		dfs(i, des, step + 1);
	}
	
}
void solve(){
	
	cin >> n >> d;

	for (int i = 1; i <= n; i++)
		scanf("%lld", &x[i]);
	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			minn = n + 2;
			for (int k = 1; k <= n; k++)
				cnt[k] = 0, vis[k] = 0;
			vis[i] = 1;
			dfs(i, j, 0);
			if (cnt[minn] == 2)ans++;
		}
	}
	printf("%lld\n", ans);
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--){
		solve();
	}
}
