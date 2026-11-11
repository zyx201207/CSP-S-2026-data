#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N];
int dp[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	dp[1] = 0;
	int ans = 0;
	int cnt = 1;
	int p = 0;
	for (int i = 2; i <= n; i++){
		int d = (a[i] - a[i - 1]) * (i - 1 - p);
		dp[i] = dp[i - 1] + d;
		cnt++;
		if (dp[i] > m){
			while (dp[i] > m){
				p++;
				dp[i] -= (a[i] - a[p]);
				cnt--;
			}
		}
		//cout << dp[i] <<" "<< d <<"\n";
		ans = max (ans, cnt);
	}
	cout << ans;
	return 0;
}
/*
-std=c++14
*/
