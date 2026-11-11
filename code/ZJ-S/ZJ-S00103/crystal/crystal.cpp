#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+50;
ll n,m,a[N],s[N],ans;
ll solve(ll x){
	ll lo=0,hi=x,mid;
	while(lo<hi){
		mid=(lo+hi)/2;
		if(a[x]*(x-mid)-s[x]+s[mid]<=m)
		hi=mid;
		else
		lo=mid+1;
	}
	return x-lo;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(ll i=1;i<=n;i++){
		ans=max(ans,solve(i));
	}
	printf("%lld",ans);
	return 0;
}
