#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll read(){
	ll f=1,x=0,c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const ll N=5e5+7;
ll a[N],m,n,sum[N],res=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(ll i=2;i<=n;i++){
		ll l=1,r=i-1,ans=i;
		while(l<=r){
			ll mid=l+r>>1;
			if((i-mid)*a[i]-(sum[i-1]-sum[mid-1])<=m){
				r=mid-1,ans=mid;
			}
			else l=mid+1;
		};
		res=max(res,i-ans+1);
	}
	printf("%lld\n",res);
	return 0;
}

