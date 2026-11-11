#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
ll s[2000011],d;
int dp[6011],p[6011],sum[6011];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T,n;
	cin>>c>>T;
	while(T--) {
		cin>>n>>d;
		int ans=0;
		for(int i=1; i<=n; i++)cin>>s[i];
		for(int i=1; i<=n; i++) {
			memset(p,0,sizeof(p));
			memset(dp,0,sizeof(dp));
			memset(sum,0,sizeof(sum));
			p[i]=sum[i]=1;
			for(int j=i+1,tot=1,pd=i; j<=n; j++) {
				if(s[j]-s[j-1]>d)break;
				while(pd<j&&s[pd]+d<s[j])pd++;
				dp[j]=dp[pd]+1;
				if(dp[j]!=dp[j-1])tot=sum[j-1],sum[j-1]=0;
				p[j]=tot-sum[pd-1],p[j]=p[j]>3?3:p[j];
//				if(dp[j]==dp[j-1])sum[j]=sum[j-1]+p[j];
//				else sum[j]=p[j];
				sum[j]=sum[j-1]+p[j];
				if(p[j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
