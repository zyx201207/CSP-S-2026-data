#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10,inf = INT_MAX-3;
long long d,a[N],dp[N];
int n,T,c,cnt[N];
inline void solve(){
	cin >> n >> d;
//	cout <<d <<endl;
	for (int i = 1;i <= n;i++){cin >> a[i];}
	long long ans = 0;
	for (int k = 1;k <= n;k++){
		for (int i = 1;i <= n;i++){cnt[i] = 0;dp[i] = inf;}
		dp[k] = 1;
		for (ll i = k+1;i <= n;i++){
			long long pos = lower_bound(a+1,a+n+1,a[i]-d) - a;
			//cout << pos << '!' << endl;
			for (ll j = pos;j <= i;j++){
				dp[i] = min(dp[i],dp[j]+1); 
			}
			for (ll j = pos;j <= i;j++){
				if (dp[i] == 1 + dp[j]){
					cnt[i]++;
				}
			}
		}
		for (int i = 1;i <= n;i++){
			//cout << dp[i] << ' ';
			if (cnt[i] == 2)
				ans++;
		}
	//	cout << endl; 
	}
	//cout <<endl;
	cout << ans << "\n";
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> T;
	while(T--){
		solve();
	}
	return 0;
} 
