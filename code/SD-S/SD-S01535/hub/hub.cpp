#include<bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ls(x) (x<<1)
#define rs(x) (x<<1 | 1)
#define mid ((l+r)>>1)

using namespace std;
typedef long long ll;
const int N=2e6+10;
const ll INF=4e18;
int f[N];
ll dep[N];
ll siz[N];
int top[N];
bool vis[N];
ll son[N];
vector<int> g[N];
void dfs(int u, int fa){
	dep[u]=dep[fa]+1;
	siz[u]=1;
	f[u]=fa;
	int maxx=-1;
	for(int v:g[u]){
		if(v==fa) continue;
		dfs(v,u);
		siz[u]+=siz[v];
		if(siz[v]>maxx){
			maxx=siz[v];
			son[u]=v;
		}
	}
	return;
}
void _dfs(int u, int topf){
	top[u]=topf;
	if(!son[u]) return;
	_dfs(son[u],topf);
	for(int v:g[u]){
		if(v==f[u]||v==son[u]) continue;
		_dfs(v,v);
	}
	return;
}
int lca(int u, int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=f[top[u]];
	}
	if(dep[v]>dep[u]) return u;
	return v;
}

ll dt(int u, int v){
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}

int _,T,n,k;
void __dfs(int u, int fa){
	vis[u]=1;
	for(auto v:g[u]){
		if(v==fa) continue;
		__dfs(v,u);
	}
	return;
}
bool c[N];

void init(){
	for(int i=1; i<=n; i++){
		f[i]=0,dep[i]=0,siz[i]=0,son[i]=0,top[i]=0,c[i]=0,vis[i]=0;	
		g[i].clear();
	}
	n=0,k=0;
	return;
}
void solve(){
	//cout<<1;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>k;
	for(int i=1,u,v; i<n; i++){
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,0);
	_dfs(1,1);
	ll ans=INF;
	for(ll i=0; i<(1<<n); i++){
		if(__builtin_popcount(i)!=k) continue; 
		for(int j=0; j<n; j++){
			c[j+1]=0;
			if((i>>j)&1){
				c[j+1]=1;
			}
		}
		
		int cnt=0;
		for(int j=1; j<=n; j++) vis[i]=0;
		for(int k=1; k<=n; k++){
			
			if(c[k]&&!vis[k]){
				
				__dfs(k,0);
				cnt++;
			}
		}
		ll res=0;
		if(cnt<=2){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					if(i==j) continue;
					if(c[i]&&c[j]){
						if(dt(i,j)==0){
							cout<<1;
						}
						res=max(res,dt(i,j));
					}	
				}
			}
			ans=min(ans,res);
		}
	}
	cout<<ans<<'\n';
	//init();
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>_>>T;
	while(T--) solve();
	return 0;
}
/*
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
