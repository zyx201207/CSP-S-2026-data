#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
ll n,m;
vll a,s;
bool check(ll x){
	for(ll i=x;i<=n;i++){
		if(x*a[i]-(s[i]-s[i-x])<=m)return 1;
	}
	return 0;
}
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	a.resize(n+1),s.resize(n+1);
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a.begin()+1,a.end());
	for(ll i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	ll l=1,r=n,mid,ans;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1; 
	}
	cout<<ans;
}

