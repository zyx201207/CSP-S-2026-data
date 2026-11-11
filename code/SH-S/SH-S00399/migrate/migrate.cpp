#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,d,a[2000009],ans;
pair<ll,ll> dp[5009][5009];
void solve() {
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			dp[i][j]={0,0x3f3f3f3f3f3f3f3f};
		}
	}
	for(int i=1;i<=n;i++) {
		dp[i][i]={1,0};
		for(int j=i+1;j<=n;j++) {
			ll dis=0x3f3f3f3f3f3f3f3f;
			for(int k=j-1;k>=i;k--) {
				if(a[j]-a[k]>d) break;
				dis=min(dis,dp[i][k].second+1);
			}
			if(dis>=0x3f3f3f3f3f3f3f3f) {
				break;
			}
			for(int k=j-1;k>=i;k--) {
				if(a[j]-a[k]>d) break;
				if(dis==dp[i][k].second+1) {
					dp[i][j].first+=dp[i][k].first;
				}
			}
			dp[i][j].second=dis;
			if(dp[i][j].first==2) {
				ans++;
				//cout<<i<<" "<<j<<"\n";
			}
		}
	}
	cout<<ans<<"\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) {
		solve();
	}
	return 0;
}
