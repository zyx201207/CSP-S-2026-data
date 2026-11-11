#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=2e6+10;
int c,t,a[N],dp[N];
void solve() {
	int n,d,ans=0;
	cin>>n>>d;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for (int x=1;x<n;x++) {
		for (int y=x+1;y<=n;y++) {
			int minn=0;
			for (int i=x;i<=y;) {
				int cnt=0;
				int j;
				for (j=1;cnt<d;j++) {
					cnt+=a[x+j]-a[x+j-1];
				}
				i+=j;
				minn++;
			}
			memset(dp,0,sizeof(dp));
			for (int i=x;i<=y;i++) {
				for (int j=x;j<i;j++) {
					if (a[j]+d>=a[i]&&(dp[j]+1<minn||i==y)) {
						dp[i]=dp[j]+1;
					}
				}
			}
			ans+=(dp[y]==2);
		}
	}
	cout<<ans<<endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--) {
		solve();
	}
	return 0;
}
