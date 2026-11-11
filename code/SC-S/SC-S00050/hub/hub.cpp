#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 5;
ll n,k,t,c,u,v,tot,cnt,f[N],vis[N],fl;
vector<ll> g[N];
void dfs(ll x,ll ft){
	vis[x]=1;
	for(auto v:g[x]) if(v!=ft&&!f[v]) dfs(v,x);
}
void dfs2(ll x,ll ft,ll dep){
	vis[x]=1;
	if(f[x]) {fl=min(fl,dep);return ;)
	for(auto v:g[x]) if(v!=ft) dfs2(v,x,dep+1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(ll i=1;i<n;i++) cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
		for(ll i=0;i<(1<<n);i++){
			tot=0;
			for(ll j=0;j<n;j++){
				tot+=((i>>j)&1);
			}
			if(tot!=k) continue;
			memset(f,0,sizeof(f));
			for(ll j=0;j<n;j++){
				if((i>>j)&1) f[i+1]=1;
			}
			tot=0;
			for(ll i=1;i<=n;i++) if(!vis[i]&&!f[i]) dfs(i,0),tot++;
			if(tot>2) continue;
			for(ll i=1;i<=n;i++) if(!f[i]) fl=1e18,dfs2(i,0,0);
			cout<<fl;
		}
	}
	return 0;
}