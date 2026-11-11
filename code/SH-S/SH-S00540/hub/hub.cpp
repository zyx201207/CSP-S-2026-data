#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int c,T,n,k;
vector<int> edge[N];
int a[N],ans=1e9,fa[N];
bool g[15][15];
void init(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int find(int x){
	if(x==fa[x]){return x;}
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
int dis[15];
bool judge(){
	init(n);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++) if(g[a[i]][a[j]]){
			merge(a[i],a[j]);
		}
	}
	int ct=0;
	for(int i=1;i<=k;i++) {
		if(find(a[i])==a[i]){ct++;}
	}
	return ct<=2;
}
void update(int u,int fa){
	for(int v:edge[u]) if(v!=fa){
		dis[v]=min(dis[v],dis[u]+1);
		update(v,u);
	}
}
void solve(){
	if(!judge()){return;}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=k;i++){
		dis[a[i]]=0;
		update(a[i],0);
	}
	int res=0;
	for(int i=1;i<=n;i++){
		res=max(res,dis[i]);
	}
	ans=min(ans,res);
}
void dfs(int i,int d){
	if(d==k+1){
		solve();
		return;
	}
	for(int j=i;j+k-d<=n;j++){
		a[d]=j;
		dfs(j+1,d+1);
	}
}
void clear(){
	for(int i=1;i<=n;i++){
		edge[i].clear();
	}
	ans=1e9;
	memset(g,0,sizeof(g));
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		clear();
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
			g[u][v]=g[v][u]=true;
		}
		dfs(1,1);
		cout<<ans<<'\n';
	}
	return 0;
} 
