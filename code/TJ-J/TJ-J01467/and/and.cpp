#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N], k, ans;
bool vis[N];
int dfs(int x, int depth){
	int ret = 0;
	if(depth == k + 1){
		return a[x];
	}
	for(int i = 1; i <= n; i++){
		if(vis[i]){
			continue;
		}
		vis[i] = 1;
		ret = max(ret, a[x] & dfs(i, depth + 1));
		vis[i] = 0;
	}
	return ret;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		ans = max(ans, dfs(i, 1));
	}
	cout << ans;
	return 0;
}
