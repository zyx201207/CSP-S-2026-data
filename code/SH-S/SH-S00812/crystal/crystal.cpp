#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+9;
ll n,m,a[N],s[N];
bool chk(ll x){
	for(ll i=1;i+x-1<=n;i++)
		if(x*a[i+x-1]-(s[i+x-1]-s[i-1])<=m)
			return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	ll l=1,r=n,md;
	while(l<r){
		md=(l+r+1)/2;
		if(chk(md))l=md;
		else r=md-1;
	}
	cout<<l;
	return 0;
}
