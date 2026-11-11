#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1000009;
ll d[N],p[N][20],tmp[N],vst[N],s[N],c,T,n,k;
vector<ll> G[N],H[N];
map<pair<ll,ll>,ll> x;
void dfs(ll u,ll fa){
	p[u][0]=fa;d[u]=d[fa]+1;
	for(ll i=1;i<=19;i++) p[u][i]=p[p[u][i-1]][i-1];
	for(ll v:G[u]){
		if(v==fa) continue;
		dfs(v,u);
	}
}
ll LCA(ll u,ll v){
	if(d[u]<d[v]) swap(u,v);
	for(ll i=19;i>=0;i--)
		if(d[p[u][i]]>=d[v]) u=p[u][i];
	if(u==v) return u;
	for(ll i=19;i>=0;i--)
		if(p[u][i]!=p[v][i]) u=p[u][i],v=p[v][i];
	return p[u][0];
}
ll dist(ll u,ll v){
	return d[u]+d[v]-2*d[LCA(u,v)];
}
void dfs2(ll u){
	vst[u]=1;
	for(ll v:H[u]){
		if(vst[v]) continue;
		dfs2(v);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;ll ans=1e18;
		for(ll i=1;i<=n;i++) G[i].clear();
		x.clear();
		for(ll i=1;i<=n-1;i++){
			ll u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
			x[{u,v}]=x[{v,u}]=1;
		}
		dfs(1,0);
		for(ll S=0;S<(1<<n);S++){
			for(ll i=1;i<=n;i++) H[i].clear();
			ll cnt=0,t=0;
			for(ll i=1;i<=n;i++)
				if((S>>(i-1))&1) s[++cnt]=i;
			if(cnt!=k) continue;
			for(ll i=1;i<=n;i++) vst[i]=0;
			for(ll i=1;i<=cnt;i++)
				for(ll j=i+1;j<=cnt;j++)
					if(x[{s[i],s[j]}]) H[s[i]].push_back(s[j]),H[s[j]].push_back(s[i]);
			for(ll i=1;i<=cnt;i++)
				if(!vst[s[i]]) dfs2(s[i]),t++;
			if(t>2) continue;
			ll mx=0;
			for(ll i=1;i<=n;i++){
				ll mn=1e18;
				for(ll j=1;j<=cnt;j++) mn=min(mn,dist(i,s[j]));
				mx=max(mx,mn);
			}
			ans=min(ans,mx);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
