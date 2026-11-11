#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2000006;
int ans,n,a[maxn],d,T,c,dp[maxn],sdp[maxn];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		for(int i=1;i<=n;i++){
			dp[i]=0;
			sdp[i]=1;
			for(int j=i+1;j<=n;j++){
				dp[j]=LLONG_MAX;
				sdp[j]=0;
				for(int k=i;k<=j;k++){
					if(a[j]-a[k]<=d){
						if(dp[k]+1>dp[j])continue;
						else if(dp[k]+1==dp[j])sdp[j]+=sdp[k];
						else dp[j]=dp[k]+1,sdp[j]=sdp[k];
					}
//					cerr<<i<<' '<<j<<' '<<k<<' '<<dp[j]<<' '<<sdp[j]<<'\n';
				}
				if(sdp[j]==2){
					ans++;
//					cerr<<i<<' '<<j<<'\n';
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
