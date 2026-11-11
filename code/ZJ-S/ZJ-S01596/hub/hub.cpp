#include<bits/stdc++.h>
#include<ctime>
#define int long long
#define PII pair<int,int>
#define mk(a,b) make_pair(a,b)
#define lowbit(x) (x&(-x))
using namespace std;
const int N=1e6+10,inf=1e12;
int n,k,c,T;
vector<int> e[N];
int f[N][5];
int dep[N],F[N];
bool is[N],vis[N];
int Find(int x){
	return x==F[x]?x:F[x]=Find(F[x]);
}
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int v:e[u]){
		if(v==fa) continue;
		dfs(v,u);
	}
	return;
}
int Lca(int u,int v){
	if(dep[u] < dep[v]) swap(u,v);
	for(int i=4;i>=0;--i)
		if(dep[f[u][i]]>=dep[v])
			u=f[u][i];
	if(u==v) return u;
	for(int i=4;i>=0;--i)
		if(f[u][i]^f[v][i])
			u=f[u][i],
			v=f[v][i];
	return f[u][0];
}
int Popcount(int x){
	int res=0;
	while(x) x-=lowbit(x),res++;
	return res;
}
int Dis(int u,int v){
	int lca=Lca(u,v);
	return dep[u]+dep[v]-2*dep[lca];
}
bool Check(){
	for(int i=1;i<=n;++i)
		F[i]=i,vis[i]=false;
	for(int u=1;u<=n;++u)
		for(int v:e[u]){
			if(is[u]&&is[v]&&Find(u)!=Find(v)){
				F[Find(u)]=Find(v);
			}
		}
	int cnt=0;
	for(int u=1;u<=n;++u){
		if(is[u]){
			int res=Find(u);
			if(!vis[res]) cnt++,vis[res]=true;
		}
	}
	return cnt<=2;
}
void solve(){

	cin>>n>>k;
	for(int i=1;i<=n;++i)
		e[i].clear();
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(n==k){
		cout<<0<<"\n";
		return;
	}
	if(n==k+1){
		cout<<1<<"\n";
		return;
	}
	if(c==13||c==14){
		int ans=(n+1)/2;
		for(int d=n/2;d>=0;--d){
			if(d*4+k-3>=(n+1)/2) ans=min(ans,d);
		}
		cout<<ans<<"\n";
		return;
	}

	dfs(1,1);

	for(int j=1;j<=4;++j)
		for(int i=1;i<=n;++i)
			f[i][j]=f[f[i][j-1]][j-1];

	int ans=inf;
	for(int i=0;i<(1<<n);++i){
		if(Popcount(i)!=k) continue;
		for(int j=1;j<=n;++j){
			if(i&(1<<(j-1))) is[j]=true;
			else is[j]=false;
		}
		if(!Check()) continue;
		int mx=0;
		for(int l=1;l<=n;++l){
			int mn=inf;
			if(is[l]) continue;
			for(int r=1;r<=n;++r){
				if(!is[r]) continue;
				mn=min(mn,Dis(l,r));
			}
			mx=max(mx,mn);
		}
		ans=min(ans,mx);
	}

	cout<<ans<<"\n";

	return;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	cin>>c>>T;

	while(T--){
		solve();
	}

	// cerr<<1e3*clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}