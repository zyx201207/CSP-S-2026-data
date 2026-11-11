#include <bits/stdc++.h>
using namespace std;
const int N=105,inf=1e9;
int c,t;
int n,k;
int h[N],e[N*2],ne[N*2],idx=0;

int fa[N][20],depth[N];
int dist[N][N];

void add(int u,int v){
	e[idx]=v,ne[idx]=h[u],h[u]=idx++;
}
void dfs_get(int u,int f){
	depth[u]=depth[f]+1;
	fa[u][0]=f;
	for(int i=1;i<20;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(int i=h[u];~i;i=ne[i]){
		int v=e[i];
		if(v==f)continue;
		dfs_get(v,u);
	}
}
int lca(int x,int y){
	if(x==y)return x;
	if(depth[x]<depth[y])swap(x,y);
	for(int i=19;i>=0;i--){
		if(depth[fa[x][i]]>=depth[y])x=fa[x][i];
	}
	if(x==y)return x;
	for(int i=19;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i],y=fa[y][i];
		}
	}
	return fa[x][0];
}

int a[N];
int ans;
bool st[N];

void dfs_check(int u){
	st[u]=0;
	for(int i=h[u];~i;i=ne[i]){
		int v=e[i];
		if(st[v]==0)continue;
		dfs_check(v);
	}
}
bool check(){
	int num=0;
	for(int i=1;i<=k;i++){
		if(st[a[i]]==1){
			num++;
			if(num>2)return false;
			dfs_check(a[i]);
		}
	}
	return true;
}
void dfs(int x,int cnt){
	if(x==n+1)return;
	if(cnt==k){
		if(check()){
			int res=0;
			for(int i=1;i<=n;i++){
				int num=inf;
				for(int j=1;j<=k;j++){
					num=min(num,dist[i][a[j]]);
				}
				res=max(res,num);
			}
			ans=min(ans,res);
		}
		return;
	}
	dfs(x+1,cnt);
	
	a[cnt+1]=x,st[x]=1;
	dfs(x+1,cnt+1);
	st[x]=0;
}
void init(){
	memset(h,-1,sizeof h);
	idx=0;
	ans=inf;
	memset(st,0,sizeof st);
	memset(fa,0,sizeof fa);
	memset(dist,0,sizeof dist);
	memset(a,0,sizeof a);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		init();
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			add(u,v),add(v,u);
		}
		dfs_get(1,0);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int l=lca(i,j);
				dist[i][j]=dist[j][i]=depth[i]+depth[j]-2*depth[l];
				//cout<<i<<" "<<j<<" "<<l<<" "<<dist[i][j]<<"\n";
			}
		}
		
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
