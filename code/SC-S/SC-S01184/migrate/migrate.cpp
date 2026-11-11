#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t;
ll n,d;
ll a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof a);
		ll ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		for(ll i=1;i<n;i++){
			ll cnt1=0;
			for(ll j=i+1;j<=n;j++){
				if(a[j]>a[i]+d){
					cnt1=j-1;
					break;
				}
			}
			if(cnt1==0||cnt1==i){
				break;
			}
			ll cnt2=cnt1-1;
			bool f=0;
			for(ll j=cnt1+1;j<=n;j++){
				if(a[j]>a[cnt2]+d){
					if(j-1==cnt1){
						ans--;
					}
					ans++;
					f=1;
					break;
				}
				if(a[j]==a[cnt2]+d){
					ans++;
					f=1;
					break;
				}
			}
			if(!f){
				break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}