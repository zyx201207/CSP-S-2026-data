#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=2e6+1;
int c,t,n,cnt[5001][5001];
ll d,x[maxn],dp[5001][5001],ans;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		for(int i=1;i<=n;i++) {
			cin>>x[i];
		}
		if(c<=6) {
			ans=0;
			memset(cnt,0x3f,sizeof cnt);
			memset(dp,0,sizeof dp);
			for(int i=1;i<=n;i++) {
				cnt[i][i]=0;
				dp[i][i]=1;
			}
			for(int k=2;k<=n;k++) {
				for(int l=1;l+k-1<=n;l++) {
					int r=l+k-1;
					for(int m=r-1;m>=l;m--) {
						if(x[r]-x[m]>d) {
							break;
						}
						if(cnt[l][m]+1==cnt[l][r]) {
							dp[l][r]+=dp[l][m];
						}
						else if(cnt[l][m]+1<cnt[l][r]) {
							dp[l][r]=dp[l][m];
							cnt[l][r]=cnt[l][m]+1;
						}
					}
				}
			}
			for(int i=1;i<=n;i++) {
				for(int j=1;j<i;j++) {
					if(dp[j][i]==2) {
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
		else if(c==11||c==12) {
			ll e=x[2]-x[1];
			if(d>=2*e&&n-2*d/e+1>0) {
				cout<<n-2*d/e+1<<endl;
			}
			else {
				cout<<0<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
