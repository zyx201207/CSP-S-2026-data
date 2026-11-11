#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int m, n, g[N], ans[N], anst, len;
bool vis[N];
void dfs(int x){
	for(int i = x + 1; i <= m; ++i){
		if(len == m){
			continue;
		}
		len++;
		if(vis[i]){
			ans[i] = max(ans[i-1]&g[i], ans[i]);
		}else{
			vis[i] = true;
			ans[i] = ans[i-1]&g[i];
		}
		dfs(i);
		len--;
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> g[i];
		ans[i] = g[i];
	}
	len = 1;
	dfs(1);
	for(int i = 1; i <= n; ++i){
		anst = max(ans[i], anst);
	}
	cout << anst << '\n';
	return 0;
}
