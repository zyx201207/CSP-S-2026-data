#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll n,m,k,ans;
ll a[N],pre[N];
ll solve(ll x){
	ll l=1,r=x,mid,sum=x;
	while(l<=r){
		mid=l+r>>1;
		if(a[x]*(x-mid)-(pre[x-1]-pre[mid-1])<=m){
			sum=mid;
			r=mid-1;
		}else l=mid+1;
	}
//	cout<<"*";
//	cout<<sum<<" "<<a[x]*(x-sum)-(pre[x-1]-pre[sum-1])<<"\n";
	return sum;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ans=1;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(ll i=2;i<=n;i++){
		ll tmp=solve(i);
		ans=max(ans,i-tmp+1);
	}
	cout<<ans<<"\n";
	return 0;
}
/*
5 5 
1 2 4 8 9
5 8 
-3 -1 2 2 7
*/
