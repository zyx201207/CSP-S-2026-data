#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+9;
ll c,t;
ll n,d,x[N];
ll fl[N],fr[N];
ll cnt[N],pre[N],mn[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t); 
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(ll i=1;i<=n;i++){
			fl[i]=lower_bound(x+1,x+i+1,x[i]-d)-x;
			fr[i]=i-1;
		}
		ll ans=0;
		for(ll k=1;k<n;k++){
			cnt[k-1]=pre[k-1]=mn[k-1]=0;
			cnt[k]=1,pre[k]=1,mn[k]=0;
			for(ll i=k+1;i<=n;i++){
				if(max(fl[i],k)==i){
					cnt[i]=0;
					pre[i]=pre[i-1];
					mn[i]=mn[i-1];
					continue;
				}
				cnt[i]=pre[max(k,min(fr[i],upper_bound(mn+max(fl[i],k)+1,mn+i,mn[max(fl[i],k)])-mn-1))]-pre[max(fl[i],k)-1];
				pre[i]=pre[i-1]+cnt[i];
				mn[i]=mn[max(fl[i],k)]+1;
				if(cnt[i]==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
}
