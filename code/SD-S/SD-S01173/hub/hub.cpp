#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pr pair<int,int>
#define mk(a,b) make_pair(a,b)
#define Tnow double(clock())/CLOCKS_PER_SEC
double TT=double(clock())/CLOCKS_PER_SEC;

const int N=5e5+5,inf=INT_MAX-1;

int id,n,k,fa[N][21],vis[N],c[N];
vector<int> G[N];
int dep[N];

void dfs(int u,int lst){
	dep[u]=dep[lst]+1;
	fa[u][0]=lst;
	for(int i=1;i<21;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:G[u]){
		if(v==lst) continue;
		dfs(v,u);
	}return ;
}

int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=20;i>=0;i--) if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
	if(u==v) return u;
	for(int i=20;i>=0;i--){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	}	
	return fa[u][0];
}

void dfs1(int u){
	vis[u]=1;
	for(auto v:G[u]){
		if(vis[v]||c[v]==0) continue;
		dfs1(v);
	}
	return ;
}

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		c[i]=vis[i]=dep[i]=0,G[i].clear();
		for(int j=0;j<21;j++) fa[i][j]=0;
	}
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	for(int i=n;i>=n-k+1;i--) c[i]=1;
	int ans=inf;
	do{
		int kuai=0,fl=0;
		vector<int> ky;
		ky.clear();
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=n;i++){
			if(c[i]) ky.push_back(i);
			if(c[i]==0||vis[i]) continue;
			kuai++;
			if(kuai>2){
				fl=-1;
				break;
			}
			dfs1(i);
		}
		if(fl==-1) continue;
		int maxx=0;
		for(int u=1;u<=n;u++){
			if(c[u]) continue;
			int Min=inf;
			for(auto v:ky) Min=min(Min,dep[u]+dep[v]-2*dep[lca(u,v)]);
			maxx=max(maxx,Min);
		}
		ans=min(ans,maxx);
		if(Tnow-TT>=0.985){
			cout<<ans<<endl;
			return ;
		}
	}while(next_permutation(c+1,c+n+1));
	memset(c,0,sizeof c);
	cout<<ans<<endl;
	return ;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int _T; cin>>id>>_T;
	while(_T--) solve();
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
