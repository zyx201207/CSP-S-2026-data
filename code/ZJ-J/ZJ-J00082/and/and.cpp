#include<bits/stdc++.h>
using namespace std;
int n, m, cnt, a[200010], vis[200010], mx;
long long ans, r, sum;
void dfs(int t, long long res){
	if(cnt == m){
		ans = max(ans, res);
		return;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i] == 0){
			vis[i] = 1;
			cnt++;
			dfs(i, res & a[i]);
			cnt--;
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}
	for(int i = 1; i <= 31; i++){
		r *= 2;
	}
	if(m == 1){
		cout << mx;
		return 0;
	}
	if(m == n){
		sum = a[1];
		for(int i = 2; i <= n; i++){
			sum = sum & a[i];
		}
		cout << sum;
		return 0;
	}
	dfs(0, r - 1);
	cout << ans;
	return 0;
}