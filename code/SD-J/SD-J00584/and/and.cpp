#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=0,sum=0;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<m;j++){
			sum=a[i]&a[i+1];
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
} 
