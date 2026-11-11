#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> a;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		ll t;
		cin>>t;
		a.push_back(t);
	}
	ll mx=-1;
	if(m==1){
		for(ll i=0;i<a.size();i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}
	if(m==2){
		for(ll i=0;i<a.size();i++){
			for(ll j=i+1;j<a.size();j++){
				ll ans=a[i]&a[j];
				mx=max(mx,ans);
				//cout<<a[i]<<" "<<a[j]<<" "<<ans<<endl;
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==3){
		for(ll i=0;i<a.size();i++){
			for(ll j=i+1;j<a.size();j++){
				for(ll k=j+1;k<a.size();k++){
					ll ans=(a[i]&a[j])&a[k];
					mx=max(mx,ans);
				}
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		ll ans=a[0];
		for(ll i=0;i<a.size();i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
