#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll c,t;

ll solve(ll n,ll m,ll l,ll r,ll num){
	ll res=0;
	res=((l-1)>0)*(m-1)*(m-1)*((n-r)>0)*num;
	return res;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdin);
	cin>>c>>t;
	while(t--){
		ll n,m;
		ll a[200010];
		ll ans=0;
		cin>>n>>m;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		if(c==11||c==12){
			for(ll i=1;i<=n;i++){
				if(n*(a[2]-a[1])%m==0&&n*(a[2]-a[1])!=m){
					continue;
				}
				ans+=(n*m-m*i);
			}
			cout<<ans<<'\n';
			continue;
		}
		if(c==13||c==14){
			if(n!=2*m){
				ans=n*(n-1)/2;
			}
			else{
				ans=(n-1)*(n-2)/2;
			}
			cout<<ans<<'\n';
			continue;
		}
		if(c==1||c==2){
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					for(ll k=j+1;k<=n;k++){
						for(ll u=k+1;u<=n;u++){
							if(a[k]-a[i]<=m&&a[u]-a[j]<=m){
								ans++;
							}
						}
					}
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i;j<=n;j++){
//				if(j-i+1%m==0){
//					continue;
//				}
				
				if(a[j]-a[i]>m){
					break;
				}
////				ll num=calc(pos);
				ans+=solve(n,m,i,j,1);
				
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
