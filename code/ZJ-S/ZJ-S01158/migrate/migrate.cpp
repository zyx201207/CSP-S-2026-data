#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,d,x[2000006],method[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ll ans=0;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
			if(i!=1)
			x[i]=x[i]-x[1];
		}
		x[1]=0;
		method[x[1]]=1;
		for(ll i=2;i<=n;i++){
			for(ll j=1;j<=d;j++){
				if(x[i]-j>=1){
					method[x[i]]+=method[x[i]-j];
				}
			}
		}
		for(ll i=3;i<=n;i++){
			method[x[i]]-=method[x[i]-1];
		}
		for(ll i=1;i<=n;i++){
			if(method[x[i]]==2){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
