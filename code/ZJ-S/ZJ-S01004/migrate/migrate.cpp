#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+9;
ll n,d,x[N],s[N],k[N],g[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>x[i];
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(x[i]+d<x[j]){
					g[i]=j-1;	
					break;
				} 
			}
			if(g[i]==0) g[i]=n;
		}
		ll cnt=0,ans=0;
		for(ll i=1;i<=n;i++) if(g[i]-i>=2 && g[g[i]]==g[g[i]-1] && g[g[i]]!=g[g[i]-2]) s[++cnt]=g[g[i]],k[cnt]=i;
		ll l=1,r=1,t=1;
		while(r<=n){
			r++;
			if((l<=k[t] && s[t]<=r && l<=k[t+1] && s[t+1]<=r)){
				ans+=(k[t]-l+1)*(r-s[t]);
				while(l<=k[t] && s[t]<=r && l<=k[t+1] && s[t+1]<=r) l++;
				t++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

