#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=2e6+10;
ll c,t,n,d,a[N];
ll f[310][310][310],sum[310];
void solve(){
	scanf("%lld%lld",&n,&d);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	ll ans=0;
	for(ll i=1;i<n;i++){
		for(ll j=0;j<=n;j++){
			sum[j]=0;
			for(ll k=0;k<=n;k++)f[i][j][k]=0;
		}
		ll l=i;
		f[i][i][0]=1;
		sum[0]=1;
		for(ll j=i+1;j<=n;j++){
			while(a[j]-a[l]>d){
				for(ll k=0;k<=n;k++)sum[k]-=f[i][l][k];
				l++;
			}
			for(ll k=n;k>=1;k--){
				f[i][j][k]=sum[k-1];
				sum[k]+=f[i][j][k];
			}
			for(ll k=1;k<=n;k++){
				if(f[i][j][k]){
					if(f[i][j][k]==2)ans++;
				    break;
				}
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)solve();
	return 0;
} 
