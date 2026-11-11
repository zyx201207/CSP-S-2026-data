#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+5;
ll n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		ll ans=-1e18;
		for(ll i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==n){
		ll sum=a[1];
		for(ll i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==2){
		ll ans=-1e18;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				ll x=a[j]&a[i];
				ans=max(ans,x);
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}