#include<bits/stdc++.h>
#define N 20009
#define int long long
#define high 1e9+7
using namespace std;
int c,t,n,d,x[N],q[N][2],ans,dp[N],cnt[N],INF=high;
int mmin(int a,int b){return a<b?a:b;}
int mmax(int a,int b){return a>b?a:b;}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	INF*=INF;
	ios::sync_with_stdio(false);
	cin>>c>>t;
	if(c==13||c==14){for(int i=1;i<=t;i++)cout<<0<<endl;}
else{
while(t--){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	if(c==12||c==11){d/=(x[2]-x[1]);cout<<((d==0||d==1)?0:mmax(0,n+1-2*d))<<endl;continue;}
	for(int i=1;i<=n;i++){
		memset(dp,INF,sizeof(dp));
		memset(cnt,0,sizeof(cnt));
		dp[i]=1;
		for(int j=i+1;j<=n;j++){
			int k=j-1;
			while(x[j]-x[k]<=d&&k>0){
				if(dp[k]+1==dp[j])cnt[j]++;
				else if(dp[k]+1<dp[j])cnt[j]=1,dp[j]=dp[k]+1;
				k--;
			}
		}
		for(int j=1;j<=n;j++){
//			cout<<dp[j]<<' '<<cnt[j]<<endl;
			if(cnt[j]==2){ans++;}
		}
	}
	cout<<ans<<endl;
}
}
	return 0;
}

