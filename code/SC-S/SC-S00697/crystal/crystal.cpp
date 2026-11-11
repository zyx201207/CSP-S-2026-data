#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=5e5+7;
ll n,m,ans=1,a[MAXN],b[MAXN];
signed main(){
#define _ON_JUDGE_CSPSa 1
#if _ON_JUDGE_CSPSa 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
#endif
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	if(n<=13000){
		for(ll r=1;r<=n;r++){
			ll l,cnt=0;
			for(l=r;l>=0;l--){
				if(cnt-a[l]+a[r]>m)break;
				cnt+=a[r]-a[l];
			}
			ans=max(ans,r-l);
		}
		printf("%lld",ans);
		return 0;
	}
	b[1]=0;
	for(ll i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		b[i]+=b[i-1];
	}
	for(ll l=1,r;l<n;l++){
		r=lower_bound(b+1,b+n+1,b[l]+m)-b;
		r=lower_bound(b+1,b+n+1,b[l]+m/(r-l))-b;
		if(b[r]-b[l-1]>m||r==n+1)r-=1;
		ans=max(ans,r-l+1);
	}
	printf("%lld",ans+1);
	return 0;
}