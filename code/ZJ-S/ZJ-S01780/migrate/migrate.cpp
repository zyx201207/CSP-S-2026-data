#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, test;
int n, vis[N];
int cnt;
long long a[N], d;
void dfs(int u, int v, int s){
	if(s == 0 && u == v){
		cnt++;
		//cout << cnt << endl;
		return ;
	}
	for(int i = u + 1; i <= v; i++){
		if(a[i] - a[u] <= d){
			if(vis[i])continue;
			vis[i] = 1;
			dfs(i, v, s - 1);
			vis[i] = 0;
		}
	}
}
void solve(){
	long long ans = 0;
	scanf("%d%lld", &n, &d);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		for(int j = i + 3; j <= n; j++){
			cnt = 0;
			if(a[j] - a[i] <= d)continue;
			int minn = (a[j] - a[i] + d - 1) / d;
			if(minn == 1 && j - i > 3)continue;
			vis[i] = 1;
			dfs(i, j, minn);
			vis[i] = 0;
			if(cnt == 2)
				ans++;
		}
	}
	printf("%lld\n", ans);
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &test);
	while(test--){
		solve();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5 

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
