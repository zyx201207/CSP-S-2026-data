#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
const ll N=2e6+5,M=5e3+5;
ll c,T;
ll n,d;
ll x[N];
ll dis[M][M],cnt[M][M];
ll nxt[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld", &c, &T);
	while(T--){
		ll ans=0;
		scanf("%lld%lld", &n, &d);
		for(ll i=1;i<=n;++i){
			scanf("%lld", &x[i]);
		}for(ll i=1;i<=n;++i){
			nxt[i]=std::max(nxt[i-1],i);
			while(nxt[i]<=n&&x[nxt[i]]-x[i]<=d) ++nxt[i];
			--nxt[i];
		}
		if(c<=10){
			for(ll i=1;i<=n;++i){
				for(ll j=1;j<=n;++j){
					dis[i][j]=cnt[i][j]=0;
				}
			}for(ll i=n;i>=1;--i){
				for(ll j=i;j<=nxt[i];++j) dis[i][j]=1,cnt[i][j]=1;
				for(ll j=nxt[i];j>=nxt[i]-2&&j>=i;--j){
					for(ll k=i+1;k<=n;++k) if(dis[j][k]&&(!dis[i][k]||dis[j][k]+1<=dis[i][k])){
						if(!dis[i][k]||dis[j][k]+1<dis[i][k]){
							dis[i][k]=dis[j][k]+1;
							cnt[i][k]=0;
						}cnt[i][k]+=cnt[j][k];
						if(cnt[i][k]>3) cnt[i][k]=3;
					}
				}for(ll k=i+1;k<=n;++k) if(cnt[i][k]==2) ++ans;
			}printf("%lld\n", ans);
		}else if(c<=12){
			if(nxt[1]<=2){
				puts("0");
				continue;
			}printf("%lld\n", std::max(0ll,n-2*nxt[1]+3));
		}else{
			for(int i=n;i>=1;--i){
				if(nxt[i]<=i+1) continue;
				if(nxt[i]==i+2){
					ans+=nxt[nxt[i]-1]-nxt[i];
					continue;
				}ans+=nxt[nxt[i]-1]-nxt[nxt[i]-2];
			}printf("%lld\n", ans);
		}
	}
	return 0;
}