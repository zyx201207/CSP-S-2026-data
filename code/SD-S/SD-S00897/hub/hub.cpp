#include <bits/stdc++.h>

using namespace std;

#define ll long long 
//#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb emplace_back

const int mod=998244353,N=12;

int c,t,n,K,u,v,b[N],di[N][N],ans,ok[N];

int d[N],fa[N];

vector<int> f[N];

int lca(int u,int v){
	if(d[u]<d[v])swap(u,v);
	while(d[u]!=d[v]){
		u=fa[u];
	}
	while(u!=v){
		u=fa[u];v=fa[v];
	}
	return u;
}

int dist(int u,int v){
	return d[u]+d[v]-2*d[lca(u,v)];
}

void dfs(int u,int f1){
	d[u]=d[f1]+1;fa[u]=f1;
	for(int v:f[u]){
		if(v==f1)continue;
		dfs(v,u);
	}
}

void dfs2(int u,int f1){
	ok[u]=1;
	for(int v:f[u]){
		if(v==f1)continue;
		if(b[v])
		dfs2(v,u);
	}
}


void check(){
	memset(ok,0,sizeof ok);int oo=0;
	for(int i=1;i<=n;i++){
		if(b[i]&&!ok[i])oo++,dfs2(i,0);
	}
	int p=0;
	if(oo<=2){
		for(int i=1;i<=n;i++){
			int num=1e9;
			if(!b[i]){
				for(int j=1;j<=n;j++){
					if(b[j])num=min(num,di[i][j]);
				}
			}
			p=max(p,num);
		}
		ans=min(ans,p);
	}
}

void dfs1(int u,int k){
	if(u==n+1&&k!=K){
		return ;
	} 
	if(u==n+1&&k==K){
		check(); 
		return ;
	}
	b[u]=1;
	dfs1(u+1,k+1);
	b[u]=0;
	dfs1(u+1,k);
}


void solve(){
	memset(ok,0,sizeof ok);
	memset(b,0,sizeof b);
	ans=1e9;
	cin>>n>>K;
	for(int i=1;i<=n;i++)
	f[i].clear();
	for(int i=1;i<n;i++){
		cin>>u>>v;
		f[u].pb(v);f[v].pb(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	di[i][j]=dist(i,j);
	dfs1(1,0);
	cout<<ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
