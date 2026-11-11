#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],dp[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) dp[i]=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			int k=i-1;
			if(x[1]+d>=dp[3]) dp[3]=1;
			while(x[k]+d>=x[i]&&k>=1){
				if(k==i-1){
					if(x[k]+d>=x[i+1]) dp[i+1]+=dp[k];
				}
				else dp[i]+=dp[k];
				k--;
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++) if(dp[i]==2) ans++;
		cout<<ans<<'\n';
	}
	return 0;
}