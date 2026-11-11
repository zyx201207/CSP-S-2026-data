// DP?
// We get the number of islands pairs more than 2 and 
//reduced it by the number of the islands pairs more than 3
// high blue or low purple
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[100005];
ll pd[100005],dpp[100005];
ll ans=0;
ll c,t;
bool dist(ll x,ll y){
	return (abs(x-y))<=m;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		ans=0;
		ll pl=0;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			if(i>=3){
				if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
					pl=1;
				}
			}
		}
//		if(pl==0){
//			ll o=a[2]-a[1];
//			if(m>=o*2&&m<o*3){
//				cout<<n*(n-1)/2-5<<endl;
//			}
//			else{
//				cout<<0<<endl;
//			}
//			continue;
//		}
		for(ll i=4;i<=n;i++){
			queue<ll> q;
			memset(pd,0,sizeof pd);
			memset(dpp,0x3f,sizeof dpp);
			pd[i]=1;
			dpp[i]=0;
			q.push(i);
			while(!q.empty()){
				ll pt=q.front();
				q.pop();
				for(ll j=pt-1;j>=1&&a[j]+m>=a[pt];j--){
					if(dpp[j]<dpp[pt]+1) continue;
					dpp[j]=dpp[pt]+1;
					if(pd[j]){
						pd[j]+=pd[pt];
						continue;
					}
					pd[j]+=pd[pt];
					q.push(j);
				}
			}
			for(ll j=1;j<=i;j++){
				if(pd[j]==2){
					ans++;
				}	
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
