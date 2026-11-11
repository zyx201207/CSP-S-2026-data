#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define unsigned long long
ll rd(){
	ll sum=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) sum=sum*10+c-'0';
	return sum*f;
}
ll n,a[500007],m,sum[500007];
bool check(ll x){
	if(x<=1) return true;
	for(int i=x;i<=n;i++){
		if(a[i]*(x-1)-sum[i-1]+sum[i-x]<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd(),m=rd();
	for(ll i=1;i<=n;i++){
		a[i]=rd();
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
