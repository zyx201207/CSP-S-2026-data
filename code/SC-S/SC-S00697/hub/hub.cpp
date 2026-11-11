#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e6+7;
ll n,m,c,k,T,ans,dist[MAXN],h[MAXN];
pair<ll,ll> a[MAXN];
signed main(){
#define _ON_JUDGE_CSPSa 1
#if _ON_JUDGE_CSPSa 
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
#endif
	scanf("%lld%lld",&c,&T);
	while(T--){
		ans=0;
		for(ll i=1;i<=n;i++){
			h[i]=0;
		}
		scanf("%lld%lld",&n,&k);
		for(ll i=1;i<n;i++){
			ll u,v;
			scanf("%lld%lld",&u,&v);
			a[i]={u,v};
		}
		for(ll i=1;i<=n;i++){
			dist[a[i].first]+=dist[a[i].second]+1;
			if(dist[i]-dist[i-1]>2){
				dist[i-1]=dist[i]+2;
			}
		}
		ll cnt=0;
		ll maxx=-1;
		for(ll i=1;i<=n;i++){
			cnt+=dist[i];
			if(dist[i]==0){
				cnt--;
			}
			maxx=max(maxx,dist[i]);
		}
		cnt-=k;
		while(cnt)
			for(ll i=1;i<=maxx&&cnt;i++){
				h[i]++;
				cnt--;
			}
		for(ll i=1;i<=maxx;i++){
			ans=max(ans,h[i]);
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}
/**
  0 2
  5 2
  1 2
  2 3
  3 4
  4 5
  10 3
  1 2
  1 3
  2 4
  2 5
  3 6
  3 7
  3 8
  7 9
  9 10
 */