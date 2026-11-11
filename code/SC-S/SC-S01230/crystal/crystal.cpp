#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out ","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<ll> d(n);
	vector<ll> c(n);
	d[1]=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	
	for(ll i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	
	ll ans=0; c[0]=0;
	for(ll i=1;i<=n;i++){
		c[i]=d[i+1]*i+c[i-1];
		if(c[i]<=m){
			ans++;
		}else break;
	}
	cout<<ans+1;
	return 0;
}