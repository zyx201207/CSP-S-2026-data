#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e6+7;
ll n,m,c,T,ans,a[MAXN],b[MAXN];
signed main(){
#define _ON_JUDGE_CSPSa 1
#if _ON_JUDGE_CSPSa 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
#endif
	scanf("%lld%lld",&c,&T);
	while(T--){
		ans=0;
		scanf("%lld%lld",&n,&m);
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			b[i]=0;
		}
		sort(a+1,a+n+1);
		b[1]=0;
		for(ll i=2;i<=n;i++){
			b[i]=a[i]-a[i-1];
			b[i]+=b[i-1];
		}
		for(ll l=1,r;l<n;l++){
			r=lower_bound(b+1,b+n+1,b[l]+m)-b;
			if(b[r]-b[l-1]>m||r==n+1)r-=1;
			if(r-l+1==2)ans++;
		}
		printf("%lld\n",ans-1);
	}
	return 0;
}