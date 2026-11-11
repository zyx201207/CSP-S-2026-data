#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

long long a[N], n, m, s, mx = -1, dp[N], ans = -1;
long long dfs(int cnt, int p, long long sum){
	if(p == m){
		return sum;
	}
	if(p < m && cnt == n){
		return -1;
	}
	for(int i = cnt + 1; i <= n; i++){
		if(sum == -1) sum = a[i];
		ans = max(ans, dfs(i, p + 1, sum & a[i]));
	}
	return ans;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i == 1) s = a[i];
		else s = a[i] & s;
		mx = max(mx, a[i]);
	}
	if(m == n) cout << s;
	else if(m == 1) cout << mx;
	else if(m == 2){
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
	}
	else if(n <= 20){
		dp[1] = mx;
		cout << dfs(0, 0, -1);
	}
	else{
		cout << 0;
	}
	return 0;
}
