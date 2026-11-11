#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i128 __int128
const int N=1e6+5;
int cas,T;
int n,k,f[N][21],deep[N];
vector<int> g[N];
void dfs(int u,int fa){
	deep[u]=deep[fa]+1;
	f[u][0]=fa;
	for(int v:g[u]){
		if(v==fa) continue;
		dfs(v,u);
	}
}
int LCA(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	int dd=deep[x]-deep[y];
	for(int i=20;i>=0;i--){
		if(dd&(1<<i)){
			x=f[x][i];
		}
	}
	if(x==y) return x;
	for(int i=20;i>=0;i++){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int dis(int x,int y){
	return deep[x]+deep[y]-2*deep[LCA(x,y)];
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>cas>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		memset(f,0,sizeof f);
		memset(deep,0,sizeof deep);
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		for(int k=1;k<=20;k++){
			for(int i=1;i<=n;i++){
				f[i][k]=f[f[i][k-1]][k-1];
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum+=dis(i,j);
			}
		}
		cout<<sum*k/n/(n+k*k/n+k*k/n+n/2)<<'\n';
	}
	return 0;
}

