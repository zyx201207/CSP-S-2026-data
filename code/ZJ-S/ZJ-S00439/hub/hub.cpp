#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7,LOG=25,inf=1e9+7;
int n,k;
int f[N][LOG];
vector<int>g[N];
int depth[N];
void dfs(int u,int fa){
	f[u][0]=fa;
//	cout<<u<<" "<<fa;
	for(int i=1;i<=20;i++)f[u][i]=f[f[u][i-1]][i-1];
	for(int v:g[u]){
		if(v==fa)continue;
		depth[v]=depth[u]+1;
		dfs(v,u);
	}
	return;
}
void init(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=20;j++)f[i][j]=1;
	}
}
int lca(int a,int b){
	if(depth[a]<depth[b])swap(a,b);
	for(int i=20;i>=0;i--){
		if(depth[f[a][i]]>=depth[b])a=f[a][i];
	}
	if(a==b)return a;
	for(int i=LOG;i>0;i--){
		if(f[a][i]!=f[b][i])a=f[a][i],b=f[b][i];
	}
	
	return f[a][0];
}

int dis(int x,int y){
	return depth[x]+depth[y]-2*depth[lca(x,y)];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		depth[1]=1;
		init();
		dfs(1,1);

		int minn=inf;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int maxx=0;
				for(int x=1;x<=n;x++){
					int s=min(dis(x,i),dis(j,x));
					maxx=max(maxx,s);
				}	
				minn=min(maxx,minn);
			}
		}
		cout<<minn-(k-2)/2<<"\n";
	}
	
	return 0;
}