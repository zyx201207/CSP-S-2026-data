#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	ll c,t,n,d;cin>>c>>t;
	while(t--&&cin>>n>>d){
		ll ret=0;
		vector<ll> x(n+1);
		for(ll i=1;i<=n;i++)cin>>x[i];
		for(ll i=1;i<n-1;i++)
			for(ll j=i+1;j<=n;j++){
				ll m=1,ans=0;
				vector<ll> cnt;
				for(ll l=i,r=l+1;r<=j;r++)if(x[r]-x[l]>m)m++,l=r-1,cnt.push_back(r-1);
				for(ll k=0;k<cnt.size();k++){
					if(x[cnt[k+1]]-x[cnt[k]-1]<m)ans++;
				}
				if(ans==1)ret++;
			}
		cout<<ret;
	}
	return 0;
}