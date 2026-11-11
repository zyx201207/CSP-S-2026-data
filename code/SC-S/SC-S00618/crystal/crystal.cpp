#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],cnt=1;
bool check(ll x){
	ll s=0;
	for(ll i=1;i<x;i++) s=s+a[x]-a[i];
	return s<=m;
}
ll ef(ll l,ll r){
	while(l<r){
		ll mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ll t=ef(1,n);
	cnt=t;
	for(int i=t+1;i<=n;i++){
		if(a[t]==a[i]) cnt++;
		else break;
	}
	cout<<cnt;
	return 0;
} 