#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,di,a[2000005],dp[2000005],sum[2000005],r[2000005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(ll ii=1;ii<=t;ii++){
		ll ans=0;
		cin>>n>>di;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		for(ll s=1;s<n;s++){
			memset(dp,0,sizeof dp);
			memset(sum,0,sizeof sum);
			dp[s]=0;
			sum[s]=1;
			for(ll j=s+1;j<=n;j++){
				ll r;
				for(ll x=s;x<=j;x++){
					if(a[j]-a[x]<=di){
						r=x;
						dp[j]=dp[x]+1;
						break;
					}
				}
				for(ll x=r;x<=j-1;x++){
					if(dp[j]-1==dp[x]){
						sum[j]+=sum[x];
					}else{
						break;
					}
				}
				if(sum[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}