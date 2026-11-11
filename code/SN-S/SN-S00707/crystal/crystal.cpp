#include"bits/stdc++.h"
#define ll long long
using namespace std;
ll n,m;
ll a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=50000){
		ll ans=0;
		for(ll i=1;i<=n;i++){
			ll linans=0;
			ll now=i;
			for(ll j=i;j<=n;j++){
				if(a[now]==a[j]){
					linans++;
				}else if(m>=abs(a[now]-a[j])*linans){
					m-=abs(a[now]-a[j])*linans;
					linans++;
					now=j;
				}else{
					break;
				}
			}
			ans=max(ans,linans);
		}
		cout<<ans;
	}else if(a[2]-a[1]==a[3]-a[2]){
		ll gongcha=a[2]-a[1];
		ll total=0;
		for(ll i=1;i<=n;i++){
			if(total+a[i]>m){
				cout<<i+1<<"\n";
				return 0;
			}else{
				total+=a[i];
			}
		}
		cout<<total<<"\n";
	}
	return 0;
}
