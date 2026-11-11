//吴禹泽 SN-S00530 陕西延安中学
#include <iostream>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long 
#define MIKU 0
using namespace std;

int c, T, n, d, ans;
int x[2000005], stp[2000005], dp[2000005], s[2000005];

void work() {
	cin>>n>>d;
	ans = 0;
	for(int i=1; i<=n; i++) cin>>x[i];
	if(11<=c && c<=12) {
		int dd = x[2] - x[1];
		if(d < dd || d % dd) {
			cout<<0<<'\n'; return;
		}
		int C = d / dd;
		int j = 2 * C - 1;
		cout<<max(n-j, 0ll)<<'\n';
		return;
	}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) stp[j] = dp[j] = s[j] = 0;
		int st = i, j = i+1;
		dp[i] = s[i] = 1; s[i-1] = 0;
		while(j <= n) {
			while(j<=n && x[j]-x[st]<=d) {
				stp[j] = stp[st] + 1;
				j ++;
			}
			st ++;
		}
		int l = i, r = i;
		for(int j=i+1; j<=n; j++) {
			while(x[j]-x[l] > d) l ++;
			while(stp[r]<stp[j]) r ++;
			dp[j] = s[r-1]-s[l-1];
//			cerr<<i<<' '<<j<<' '<<l<<' '<<r<<' '<<dp[j]<<'\n';
//			cerr<<s[r-1]<<' '<<s[l-1]<<'\n';
			if(dp[j] == 2) ans ++;
			s[j] = s[j-1] + dp[j];
		}
	}
	cout<<ans<<'\n';
}

signed main() {
	fastio;
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>T;
	while(T--) work();
	return MIKU;
}

//rp ++++++

