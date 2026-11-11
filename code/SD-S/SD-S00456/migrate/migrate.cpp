#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d;
int a[200010];
int dp[5010][5010];
int tag[5010][5010];
int kk[5010][5010];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while (T--) {
		cin>>n>>d;
		int ans=0;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
		}
		for (int i=1;i<=n;i++) {
			for (int j=i+1;j<=n;j++) {
				kk[i][j]=a[j]-a[i];
			}
		}
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				dp[i][j]=0;
			}
		}
		for (int i=1;i<=n;i++) {
			for (int j=i+1;j<=n;j++) {
				int t=(a[j]-a[i])/d;
				if ((t==1&&(a[j]-a[i])%d==0)||t==0) {
					dp[i][j]=1;
				}
				else {
					if ((a[j]-a[i])%d==0) {
						t--;
					}
					else {
						t++;
					}
					if (t>=2) ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//AC
