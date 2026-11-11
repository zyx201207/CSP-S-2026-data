#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005];
bool check(ll x){
	ll ans,sum=0;
	for(int i=1;i<=x;i++)sum+=a[x]-a[i];
	ans=sum;
	for(int i=x+1;i<=n;i++){
		sum+=x*(a[i]-a[i-1]);
		sum-=(a[i]-a[i-x]);
		ans=min(ans,sum);
	}return ans<=m;
}int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}cout<<l;
	return 0;
}
