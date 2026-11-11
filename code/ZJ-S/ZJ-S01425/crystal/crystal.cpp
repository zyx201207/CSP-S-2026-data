#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,l,r,ans;
ll a[N];
bool check(ll x){
	ll t=0;
	for(ll i=1;i<x;i++)t+=a[x]-a[i];
	for(ll i=x;i<=n;i++){
		if(t<=m)return 1;
		if(i<n)t=t-(a[i]-a[i-x+1])+(x-1)*(a[i+1]-a[i]);
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	l=1,r=n;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
}