#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+10;
ll n,m,a[N],b[N],c[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(ll i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		c[i]=c[i-1]+b[i]*(i-1);
		
		ll l=1,r=i;
		while(l<r){
			ll mid=(l+r)/2;
			if(c[i]-c[mid]-(a[i]-a[mid])*(mid-1)<=m)
				r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
//		printf("i:%lld l:%lld ans:%lld c:%lld c1:%lld\n",i,l,i-l+1,c[i],c[1]);
	}
	printf("%lld",ans);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
