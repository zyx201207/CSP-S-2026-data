#include<cstdio>
#include<algorithm>
#include<vector>
typedef long long ll;
const ll INF=1e16,N=1e6+5,M=505; 
ll n,m,d,q;
struct{
	ll nxt,v,w;
}s[N];
ll p[N],slen;
void push(ll u,ll v,ll w){
	s[++slen]={p[u],v,w};
	p[u]=slen;
	return ;
}
ll w[N];
struct fll{
	ll a,t;
};
ll dis[M][M];
std::vector<fll > hav[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld", &n);
	scanf("%lld%lld%lld%lld", &n, &m, &d, &q);
	for(ll i=1;i<=m;++i){
		scanf("%lld", &w[i]);
	}for(ll i=1,k,a,t;i<=n;++i){
		scanf("%lld", &k);
		for(ll j=1;j<=k;++j){
			scanf("%lld%lld", &a, &t);
			hav[a].push_back({i,t});
		}
	}for(ll i=1;i<=n;++i){
		for(ll j=1;j<=n;++j) if(i!=j){
			dis[i][j]=INF;
		}
	}
	for(ll i=1;i<=m;++i){
		for(ll x=0;x<(ll )hav[i].size();++x)
		for(ll y=0;y<(ll )hav[i].size();++y) {
			ll ax=hav[i][x].a,ay=hav[i][y].a,t=hav[i][x].t+hav[i][y].t;
			dis[ax][ay]=std::min(dis[ax][ay],t);
			dis[ay][ax]=std::min(dis[ay][ax],t);
		}
	}for(ll k=1;k<=n;++k){
		for(ll i=1;i<=n;++i){
			for(ll j=1;j<=n;++j){
				dis[i][j]=std::min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(ll i=1,x,y;i<=q;++i){
		scanf("%lld%lld", &x, &y);
		ll ans=INF;
		for(const fll &i:hav[x])
		for(const fll &j:hav[y])
			ans=std::min(ans,dis[i.a][j.a]+i.t+j.t);
		printf("%lld\n", w[x]+w[y]+ans);
	}
	return 0;
}