#include<bits/stdc++.h>
#define uint unsigned int
using namespace std;
uint n, m, a[200001], ans;
//bool vis[200001];
void dfs(int x, int cnt, uint sum){
	if(sum <= ans){
//		cout << sum << '\n';
		return;
	}
	if(n - x + 1 < m - cnt) return;
	if(x > n) return;
	if(cnt == m){
		ans = max(ans, sum);
//		for(int i = 1; i <= n; i++){
//			if(vis[i]) cout << a[i] << ' ';
//		}
//		cout << '\n';
		return;
	}
	for(int i = x + 1; i <= n; i++){
//		vis[i] = 1;
		dfs(i, cnt + 1, sum & a[i]);
//		vis[i] = 0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(0, 0, 0xffffffff);
	cout << ans;
	return 0;
}
