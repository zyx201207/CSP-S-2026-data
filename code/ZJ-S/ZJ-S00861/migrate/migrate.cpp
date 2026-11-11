#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
int c,t,a[50005],f[50005],dp[50005],d,ans,n;
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	for(int ii=1;ii<=t;ii++) {
		cin>>n>>d;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		ans=0;
		for(int i=1;i<=n;i++) {
			memset(f,0x3f,sizeof f);
			memset(dp,0,sizeof dp);
			f[i]=0;dp[i]=1;
			for(int j=i;j<=n;j++) {
				for(int k=i;k<j;k++) {
					if(a[j]-a[k]<=d) {
						f[j]=min(f[j],f[k]+1);
					}
				}
			}
			for(int j=i;j<=n;j++) {
				for(int k=i;k<j;k++) {
					if(a[j]-a[k]<=d) {
						if(f[j]==f[k]+1) {
							dp[j]+=dp[k];
						}
					}
				}
			}
			for(int j=i;j<=n;j++) {
				if(dp[j]==2) {
					++ans;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}