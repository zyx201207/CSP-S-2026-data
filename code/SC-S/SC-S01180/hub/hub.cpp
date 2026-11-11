#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+7;
int C,T;
int n,k,fa[N][25],dep[N];
vector<int> s[N];

void dfs(int u,int FA){
	fa[u][0]=FA,dep[u]=dep[FA]+1;
	for(int i=1;i<=log2(dep[u]);i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int v:s[u]){
		if(v==FA) continue;
		dfs(v,u);
	}
}

int lca(int x,int y){
	if(dep[y]>dep[x]) swap(x,y);
	for(int i=log2(dep[x]);i>=0;i--){
		if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	}
	if(x==y) return x;
	for(int i=log2(dep[x]);i>=0;i--){
		if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}

void solve1(){
	cin>>n>>k;
	for(int u,v,i=1;i<n;i++){
		cin>>u>>v;
		s[u].push_back(v);
		s[v].push_back(u);
	}
	dfs(1,1);
	return;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	if(C<=10)while(T--)solve1();
	return 0;
}