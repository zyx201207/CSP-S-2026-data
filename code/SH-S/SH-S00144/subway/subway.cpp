#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+9,M = 5e5+9,LG = 50;
ll c,n,m,d,q,lg = 0;
ll cnt = 0;
ll w[N];
vector<ll> to[N];
vector<ll> ct[N];
ll id[N];
ll st[LG][N];
ll dep[N],dist[N];
ll tI[N],tO[N],timer = 0;
struct edge{
	ll u,v,dis;
	bool operator<(const edge &e)const{
		return dis < e.dis;
	}
} e[M*2];
ll root(ll u){
	if(u == id[u])return u;
	return id[u] = root(id[u]);
}
void add(ll ux,ll vx,ll di){
	to[ux].push_back(vx);
	ct[ux].push_back(di);
}
void kruskal(){
	sort(e+1,e+cnt+1);
	for(ll i = 1;i <= cnt;i++){
		ll u = e[i].u,v = e[i].v,dt = e[i].dis;
		//cout << "from" << u << " to " << v<< endl;
		u = root(u),v = root(v);
		if(u != v){
			//cout << "enable" << endl;
			add(e[i].u,e[i].v,dt);
			add(e[i].v,e[i].u,dt);
			id[u] = v;
		}
	}
}
void getlog(){
	while((1<<lg)<(n+m+1))lg++;
}
void dfs(ll u,ll fa,ll depth,ll distance){
	//printf("dfs %lld %lld %lld %lld\n",u,fa,depth,distance);
	tI[u] = ++timer;
	st[0][u] = fa;
	dep[u] = depth;
	dist[u] = distance;
	for(ll i = 0;i < to[u].size();i++){
		ll v = to[u][i],dt = ct[u][i];
		if(v == fa)continue;
		dfs(v,u,depth+1,distance+dt);
	}
	tO[u] = timer;
}
void procst(){
	for(ll p = 1;p <= lg;p++){
		for(ll u = 1;u <= m+n;u++){
			st[p][u] = st[p-1][st[p-1][u]];
			//cout << "st " << p << " " << u <<" = " << st[p][u] << endl;
		}
	}
}
bool isfa(ll u,ll v){
	return tI[u]<=tI[v] && tO[u]>=tO[v];
}
ll lca(ll u,ll v){
	if(dep[u]<dep[v])swap(u,v);
	if(isfa(u,v))return u;
	if(dep[u] != dep[v])
		for(ll p = lg;p >= 0;p--){
			if(dep[st[p][u]]>dep[v])u = st[p][u];
			if(dep[u] == dep[v])break;
		}
	if(v == u)return u;
	for(ll p = 0;p <= lg;p++){
		if(isfa(st[p][u],v)){break;}
		u = st[p][u];
	}
	if(v == u)return u;
	return st[0][u];
}
int main(){
	memset(st,0,sizeof(st));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin >> c >> n >> m >> d >> q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(ll i = 1;i <= m;i++){
		scanf("%lld",&w[i]);
	}
	for(ll i = 1;i <= m+n+1;i++)id[i] = i;
	for(ll i = 1;i <= n;i++){
		ll k;
		scanf("%lld",&k);
		for(ll j = 1;j <= k;j++){
			ll a,t;
		//	cin >> a >> t;
			scanf("%lld%lld",&a,&t);
			e[++cnt] = {a,m+i,t};
		}
	}
//	for(ll i = 1;i <= cnt;i++){
//		cout << e[i].u << ' ' << e[i].v << ' ' << e[i].dis <<  endl;
//	}
	kruskal();
	//deal();
	getlog();
	dfs(1,0,1,0);
	procst();
//	cout << "www" << isfa(6,2) << endl;
//	for(int i = 1;i <= m+n;i++){
//		cout << tI[i] << ' ' << tO[i] << endl;
//	}
	for(ll i = 1;i <= q;i++){
		ll u,v;
		scanf("%lld%lld",&u,&v);
		ll lcas = lca(u,v);
		ll ansuv = w[u]+w[v]+dist[u]+dist[v]-2*dist[lcas];
		printf("%lld\n",ansuv);
	}
	return 0;
}

