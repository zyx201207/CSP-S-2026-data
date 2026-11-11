#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e5+5;
ll n,ans;
ll m,a[N],d[N];
int bound(int s){
	ll l=s,r=n,ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(d[mid]-d[s-1]-(ll)s*(a[mid]-a[s-1])<=m){
			l=mid+1;
			ans=mid;
		}
		else r=mid;
		//printf("%d %d %d\n",l,r,d[mid]-d[s-1]-s*(a[mid]-a[s-1]));
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[i]=(a[i]-a[i-1])*i;
		d[i]+=d[i-1];
	} 
	for(int i=1;i<=n;i++){
		ll t=bound(i);
		//printf("%lld\n",t);
		ans=max(ans,t-i+1);
	}
	printf("%lld",ans);
	return 0;
}
