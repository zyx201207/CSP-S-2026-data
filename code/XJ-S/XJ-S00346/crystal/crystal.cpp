#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500010],c[500010],s1[500010],s2[500010],ans;
ll cal(ll l,ll r){
	return s2[r]-s2[l-1]-(r-l+1)*s1[r+1];
}
bool cmp(const ll &a,const ll &b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<n;i++)
		c[i]=a[i+1]-a[i];
	for(ll i=n-1;i;i--)
		s1[i]=s1[i+1]+c[i];
	for(ll i=1;i<n;i++)
		s2[i]=s2[i-1]+s1[i];
	for(ll i=2;i<=n;i++){
		ll l=1,r=i-1;
		while(l+1<r){
			ll mid=(l+r)/2;
			if(cal(mid,i-1)<=m)
				r=mid;
			else
				l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
	return 0;
}
