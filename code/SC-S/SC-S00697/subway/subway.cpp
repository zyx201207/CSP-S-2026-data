#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=5e5+7;
ll n,m,c,a[MAXN],T,d,q;
signed main(){
#define _ON_JUDGE_CSPSa 1
#if _ON_JUDGE_CSPSa 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
#endif
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(ll i=1;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+m+1);
	for(ll i=1;i<=m;i++){
		a[i]+=a[i-1];
	}
	ll k,p;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&k);
		for(ll j=1;j<=2*k;j++){
			scanf("%lld",&p);
		}
	}
	ll x,y;
	while(q--){
		scanf("%lld%lld",&x,&y);
		if(y>x)swap(x,y);
		printf("%lld\n",a[x]-a[y-1]);
	}
	return 0;
}