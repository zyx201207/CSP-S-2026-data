#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
const int N = 2e5+10;
int a[N], vis[N];
int mx = 0;
int p;
void dfs(int x, int sum, int cnt ){
	if(cnt == m){
		mx = max(mx, sum);
		return ;
	}
	vis[x] = 1;
	for(int i = x+1; i <= n; i++){
		if(vis[i])continue;
		dfs(i, sum & a[i], cnt+1);
		vis[i] = 0;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	if(n == m){
		int j = a[1];
		for(int i = 2; i <= n; i++){
			j &= a[i];
		}
		cout << j;
	}
	else {
		for(int i = 1; i <= n; i++){
			memset(vis, 0, sizeof vis);
			dfs(i, a[i], 1);
		}
		cout << mx;
	}
	return 0;
}


