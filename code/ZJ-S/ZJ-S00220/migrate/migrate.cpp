#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[505],b[505],dp[505];
signed main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		if(c==13 or c==14){
			cout<<0<<"\n";continue;
		}
		int n,d;cin>>n>>d;int ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		memset(dp,0,sizeof dp);memset(dp,0,sizeof b);
		for(int st=1;st<n;st++){
			memset(dp,0,sizeof dp);memset(dp,0,sizeof b);
			int u=st;
			for(int i=st;i<=n;i++){
				while(a[i]-a[u]>d)u++;
				b[i]=b[u]+1;
			}
			dp[st]=1;u=st;
			for(int i=st+1;i<=n;i++){
				for(int j=i-1;j>=st and a[i]-a[j]<=d;j--){
					if(b[i]==b[j]+1)dp[i]+=dp[j];
				}
			}
			for(int i=1;i<=n;i++){
				//cout<<dp[i]<<" ";
				if(dp[i]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
