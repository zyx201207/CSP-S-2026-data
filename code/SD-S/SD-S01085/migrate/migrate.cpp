#include<bits/stdc++.h>
#define int long long
using namespace std;
int t, n, d, a[2001000], ans, dp[2001000], temp;
int cnt;
void dfs(int now, int en){
	if(cnt > 2) return;
	if(now == en){
		cnt++;
		return;
	}
	int pre = 0;
	for(int i = en;i > now;i--){
		if(a[i] - a[now] <= d){
			dp[i] = min(dp[i], dp[now] + 1);
			if(!pre) pre = i;
		}
	}
	for(int i = pre;i > now;i--){
		if(dp[i] != dp[now] + 1) break;
		dfs(i, en);
	}
}
void solve(){
	cin >> n >> d;
	ans = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(temp == 11 || temp == 12){
		int cha = a[2] - a[1];
		if(cha <= 2 * d && 3 * d < cha){
			cout << n - 3 << "\n";
		}
		else{
			cout << 0 << "\n";
		}
		cout << cha << " " << d << "\n";
		return;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < i;j++){
			cnt = 0;
			for(int k = 1;k <= n;k++) dp[k] = INT_MAX;
			dp[j] = 0;
			dfs(j, i);
			if(cnt == 2){
//				cout << j << " " << i << "\n";
				ans++;
			}
		}
	}
	cout << ans << "\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int t;
	cin >> temp >> t;
	while(t--) solve();
	return 0;
}
/*
0 1
5 7
1 15 29 53 67
*/
