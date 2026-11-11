#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll c,T,n,d,w[2100],dp[310],cnt[310];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>w[i];
		if(c==11||c==12){
			ll x=w[2]-w[1];
			if(d<2*x||d>=3*x)cout<<0<<'\n';
			else{
				cout<<(n>3?n-3:0)<<'\n';
			}
		}else{
			ll ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)dp[j]=inf,cnt[j]=0;
				dp[i]=0;cnt[i]=1;
				for(int j=i;j<=n;j++){
					for(int k=j-1;k>=i&&w[j]-w[k]<=d;k--){
						if(dp[k]+1<dp[j]){
							dp[j]=dp[k]+1;
							cnt[j]=cnt[k];
						}else if(dp[k]+1==dp[j])cnt[j]++;
						if(cnt[j]>2)break;
					}
					ans+=(cnt[j]==2);
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}//rp++ rp++ rp++ rp++ rp++