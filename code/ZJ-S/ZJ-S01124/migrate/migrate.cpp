#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,a[2000010];
ll dp[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ll ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int id1=1;id1<=n;id1++){
			for(int id2=id1+1;id2<=n;id2++){
				for(int i=1;i<=n;i++) dp[i]=1e18;
				dp[id1]=0;
				for(int i=id1+1;i<=id2;i++){
					for(int j=i-1;j>=id1;j--){
						if(a[i]-a[j]>d) break;
						if(dp[j]!=1e18) dp[i]=min(dp[i],dp[j]+1);
					}
				}
				ll mi=dp[id2];
				if(mi!=1e18){
					for(int i=1;i<=n;i++) dp[i]=1e18;
					dp[id1]=0;
					ll cnt=0;
					for(int i=id1+1;i<=id2;i++){
						for(int j=i-1;j>=id1;j--){
							if(a[i]-a[j]>d) break;
							if(dp[j]!=1e18) dp[i]=min(dp[i],dp[j]+1);
							if(dp[j]!=1e18&&i==id2&&dp[j]+1==mi) cnt++;
						}
					}
					if(cnt==2){
						ans++;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
