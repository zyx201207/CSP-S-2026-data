#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
const int N=5e3+5,mod=1e9+7,M=2e6+5;
int dp[N][N],f[N][N],a[M];
ull sum[N][N];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=dp[i][j]=sum[i][j]=0;
		int ans=0;
		for(int s=1;s<=n;s++){
			f[s][s]=1,sum[s][s]=1;
			for(int i=s+1;i<=n;i++){
				if(a[i]-a[i-1]>d) break;
				int pos=lower_bound(a+s,a+n+1,a[i]-d)-a;
				dp[s][i]=dp[s][pos]+1;
				int r=upper_bound(dp[s]+pos,dp[s]+i,dp[s][pos])-dp[s]-1;
				//cout<<pos<<" "<<r<<endl;
				f[s][i]=sum[s][r]-sum[s][pos-1],sum[s][i]=sum[s][i-1]+f[s][i];
			}
			for(int i=s+1;i<=n;i++){
				if(f[s][i]==2 and dp[s][i]!=0) ans++;
				//cout<<f[s][i]<<" "<<dp[s][i]<<endl;
			}
		}cout<<ans<<"\n";
	}
	return 0;
}
