#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200050], bj[200050], ans[200050], maxn = -1;
void dfs(int x){
	if(x > m){
		int res = ans[1];
		for(int i = 2; i <= m; i++){
			res &= ans[i];
		}
		maxn = max(res, maxn);
		return;
	}
	for(int i = 1; i <= n; i++){
		if(bj[i] == 0){
			ans[x] = a[i];
			bj[i] = 1;
			dfs(x + 1);
			bj[i] = 0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1);
	cout << maxn;
	return 0;
}

