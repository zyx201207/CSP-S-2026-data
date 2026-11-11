#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, t, n, k, f[1000005], chose[15], minn, vis[1000005], fa[25][1000005], dis[1000005], every[105][105];
ll dep[1000005], fn[1000005];
vector<ll>vec[1000005];
ll find(ll x){
	return x==f[x]?x:f[x]=find(f[x]);
}
void dfn(ll u, ll f){
	fa[0][u]=f;dis[u]=dis[f]+1;
	for(ll i=1; i<=20; i++)fa[i][u]=fa[i-1][fa[i-1][u]];
	for(auto v:vec[u]){
		if(v!=f)dfn(v, u);
	}
}
ll lca(ll u, ll v){
	if(dis[u]<dis[v])swap(u, v);
	for(ll i=20; i>=0; i--){
		if(dis[fa[i][u]]>=dis[v])u=fa[i][u];
	}
	if(u==v)return u;
	for(ll i=20; i>=0; i--){
		if(fa[i][u]>=fa[i][v])u=fa[i][u], v=fa[i][v];
	}
	return fa[0][u];
}
void dfs(ll id){
	if(id>k){
		ll maxn=0;
		for(ll i=1; i<=n; i++){
			f[i]=i;
		}
		for(ll i=1; i<=k; i++){
			for(auto v:vec[chose[i]]){
				if(vis[v]){
					f[find(chose[i])]=f[find(v)];
				}
			}
		}
		ll sum=0;
		for(ll i=1; i<=k; i++){
			sum+=(chose[i]==find(chose[i]));
		}
		if(sum>2)return;
//		for(ll i=1; i<=k; i++)cout<<chose[i]<<' ';cout<<'\n';
		for(ll i=1; i<=n; i++){
			ll mn=1e18;
			for(ll j=1; j<=k; j++){
				ll u=i, v=chose[j], lc=lca(u, v), lon=dis[u]+dis[v]-dis[lc]*2;
				mn=min(mn, lon);
			}
//			cout<<i<<':'<<mn<<'\n';
			maxn=max(maxn, mn);
		}
		minn=min(minn, maxn);
//		cout<<'\n';
		return;
	}
	for(ll i=chose[id-1]+1; i<=n-k+id; i++){
		chose[id]=i;
		vis[i]=1;
		dfs(id+1);
		vis[i]=0;
	}
}
void solve(){
	cin >> n >> k;minn=1e18;
	for(ll i=1; i<=n; i++)vec[i].clear();
	for(ll i=1; i<n; i++){
		ll u, v;cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfn(1, 0);dfs(1);
	cout<<minn<<'\n';
}
bool check(ll x){
	return rand()%2;
}
ll ds(ll i, ll j){
	ll u=i, v=j, lc=lca(u, v), lon=dis[u]+dis[v]-dis[lc]*2;
	return lon;
}
void dsf(ll u, ll f){
	dep[u]=dep[f]+1;fn[u]=f;
	for(auto v:vec[u]){
		if(v!=f)dsf(v, u);
	}
}
void solve2(){
	cin >> n >> k;minn=1e18;
	for(ll i=1; i<=n; i++)vec[i].clear();
	for(ll i=1; i<n; i++){
		ll u, v;cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfn(1, 0);dsf(1, 0);
	ll id1=max_element(dep+1, dep+1+n)-dep;dsf(id1, 0);
	ll id2=max_element(dep+1, dep+1+n)-dep, maxn=dep[id2]/3;
	ll u1=id2, u2;
	ll xx=maxn;
	while(xx--)u1=fn[u1];u2=u1;xx=maxn;
	while(xx--)u2=fn[u2];
	maxn=0;
	for(ll k=1; k<=n; k++){
		maxn=max(maxn, min(ds(u1, k), ds(u2, k)));
	}
	cout<<n/k<<'\n';
}
int main(){
	srand(time(NULL));
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub4.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--){
//		solve2();
		if(c<=3||c==7)solve();//15·Ö 
		else solve2();
	}
	return 0;
}

