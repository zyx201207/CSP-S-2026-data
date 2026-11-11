#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005];
bool check(ll x){
	ll sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x) sum+=x-a[i];
	}
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll l=0,r=0;
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		r=max(r,a[i]);
		l=min(l,a[i]); 
	}
	while(l<=r){
		ll mid=l+(r-l)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	while(l){
		if(check(l)) l++;
		else break;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=l-1) ans++;
	}
	printf("%lld",ans);
	return 0;
}
