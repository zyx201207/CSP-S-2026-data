#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m,a[N],ans=1,pre[N];
bool ck(ll x){
	ll cnt=LLONG_MAX;
	for(ll rp=x;rp<=n;rp++){
		ll lp=rp-x+1;
		ll sum=pre[rp-1]-pre[lp-1];
		ll n_cnt=a[rp]*(x-1)-sum;
		cnt=min(cnt,n_cnt);
	}
	if(cnt<=m) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(ck(mid)) ans=max(mid,ans),l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
} 
