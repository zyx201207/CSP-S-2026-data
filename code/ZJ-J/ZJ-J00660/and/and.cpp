#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n, m;
long long a[N], ans = 0;
void dfs(int x, int d, long long cnt){
	if(d >= m){
		ans = max(ans, cnt); return ;
	}
	for(int i = x+1; i <= n; i++){
		dfs(i, d+1, cnt&a[i]);
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n-m+1; i++){
		dfs(i, 1, a[i]);
	}
	cout << ans;
	return 0;
}