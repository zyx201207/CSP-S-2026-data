#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200010;
const int LOG=20;

vector<int> g[MAXN];
int fa[LOG][MAXN];
ll dep[MAXN];
void dfs(int u,int f){
	fa[0][u]=f;
	for(int i=1;i<LOG;i++){
		fa[i][u]=fa[i-1][fa[i-1][u]];
	} 
	for(int v:g[u]){
		if(v!=f){
			dep[v]=dep[u]+1;
			dfs(v,u);
		}
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v]){
		swap(u,v);
	}
	for(int i=LOG-1;i>=0;i--){
		if(fa[i][u]!=fa[i][v]){
			u=fa[i][u];
		}
		
	}
	if(u==v){
		return u;
	}
	for(int i=LOG-1;i>=0;i--){
		u=fa[i][u];
		v=fa[i][v];
	}
	return fa[0][u];
}
ll dist(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		memset(dep,0x3f,sizeof(dep));
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ll minn=LLONG_MAX;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				minn=min(minn,dist(i,j));
			}
		}
		cout<<minn/2<<"\n";
	}
	return 0;
} 
