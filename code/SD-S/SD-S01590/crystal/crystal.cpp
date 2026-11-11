#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll n,m,a[N];
ll sum[N];
bool check(ll k){
	for(ll i=1;i+k-1<=n;i++){
		if(sum[i+k-1]-sum[i-1]+m>=a[i+k-1]*k) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	sum[n+1]=sum[n];
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l<<'\n';
	return 0;
} 
