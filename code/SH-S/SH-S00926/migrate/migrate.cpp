#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long c, test;
void solve(){
	long long n, d, ans = 0;
	cin >> n >> d;
	if(n <= 3){
		cout << 0 << endl;
		return ;
	}
	vector<ll> x(n+1);
	for(long long i=1; i<=n; i++){
		cin >> x[i];
	}
	if(c >= 13 && c <= 14){
		for(int i=1; i<=n; i++){
			int st = upper_bound(x.begin()+1, x.end(), x[i]+d) - x.begin();
			if(st > n) break;
			int sta = upper_bound(x.begin()+1, x.end(), x[st-2] + d) - x.begin()-1;
			int stat = upper_bound(x.begin()+1, x.end(), x[st-3] + d) - x.begin();
			ans += sta - stat + 1;
		}
		cout << ans << endl;
		return ;
	}
	if(c >= 11 && c <= 12){
		d = (x[2] - x[1]) * (d / (x[2] - x[1]));
		for(int cnt = 1; cnt * d <= x[n] - x[1]; cnt++){
			for(int i=1; i<=n; i++){
				int st = upper_bound(x.begin()+1, x.end(), x[i]+d*cnt) - x.begin();
				if(st > n) break;
				int sta = upper_bound(x.begin()+1, x.end(), x[st-2] + d) - x.begin()-1;
				int stat = upper_bound(x.begin()+1, x.end(), x[st-3] + d) - x.begin();
				ans += sta - stat + 1;
			}
		}
		cout << ans << endl;
		return ;
	}
	for(long long i=4; i<=n; i++){
		vector<ll> dp(n+1, -1);
		dp[i] = 0;
		for(long long j=i-1; j>=1; j--){
			ll k = min(i, upper_bound(x.begin()+1, x.end(), x[j] + d) - x.begin() - 1);
			if(dp[k] == -1) break;
			dp[j] = dp[k] + 1;
			if(dp[k] == dp[k-1] && dp[k-1] != dp[k-2]){
				ans++;
			}
		}
	}
	
	
//	for(int count = 1; count * d <= x[n] - x[1]; count++){
//		for(int i=1; i<=n; i++){
//			int st = upper_bound(x.begin()+1, x.end(), x[i] + count * d) - x.begin();
//			if(st > n) break;
//			int sta = upper_bound(x.begin()+1, x.end(), x[st-2] + d) - x.begin() - 1;
//			int stat = upper_bound(x.begin()+1, x.end(), x[st-2] + d) - x.begin();
//			ans += sta - stat + 1;
//		}
//	}
	cout << ans << endl;
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> test;
	while(test--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
