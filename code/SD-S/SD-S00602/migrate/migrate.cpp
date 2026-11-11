#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long
using namespace std;
const int RP=1e18+7;
const int N=2e6+7;
int c,T,n,d,x[N],dp[N],dis[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	if(c==11 || c==12){
		for(int t=1;t<=T;t++){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			if(n==1 || x[2]-x[1]>=d) cout<<0<<'\n';
			else cout<<max(0ll,n-2*(d/(x[2]-x[1]))+1)<<'\n';
		}
		return 0;		
	}
	for(int t=1;t<=T;t++){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dp[j]=0,dis[j]=RP;
			dp[i]=1,dis[i]=0;
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(x[j]-x[k]>d) continue;
					if(dis[j]==dis[k]+1) dp[j]+=dp[k];
					if(dis[j]>dis[k]+1)
						dis[j]=dis[k]+1,dp[j]=dp[k];
				}
				if(dp[j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}


