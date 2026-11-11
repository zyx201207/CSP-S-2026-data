#include<bits/stdc++.h>
using namespace std;
int C,T;
int n,k;
struct node{
	int v,nxt;
}a[2000005];
int head[1000005],tot;
void add(int u,int v){
	a[++tot].v=v;
	a[tot].nxt=head[u];
	head[u]=tot;
	return;
}
int dep[1000005];
int f[1000005][25];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=a[i].nxt){
		int y=a[i].v;
		if(y==fa)continue;
		dfs(y,x);
	}
	return;
}
int lca(int x,int y){
	if(dep[y]>dep[x])swap(x,y);
	for(int i=20;i>=0;i--)if(dep[f[x][i]]>=dep[y])x=f[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
int get(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
int vis[1000005],c[1000005];
void dfs2(int x){
	vis[x]=1;
	for(int i=head[x];i;i=a[i].nxt){
		int y=a[i].v;
		if(vis[y]||!c[y])continue;
		dfs2(y);
	}
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		dfs(1,0);
		if(n<=10){
			int ans=1e9;
			for(int i=0;i<(1<<n);i++){
				int cntc=0,cnt=0;
				for(int j=1;j<=n;j++){
					if(i&(1<<(j-1)))c[j]=1,cntc++;
					else c[j]=0;
					vis[j]=0;
				}
				if(cntc>k)continue;
				for(int j=1;j<=n;j++)if(c[j]&&!vis[j])cnt++,dfs2(j);
				if(cnt>2)continue;
				int maxx=0;
				for(int j=1;j<=n;j++){
					int minn=1e9;
					for(int p=1;p<=n;p++){
						if(c[p]==1)minn=min(minn,get(j,p));
					}
					maxx=max(maxx,minn);
				}
				ans=min(ans,maxx);
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=tot;i++)a[i].v=0,a[i].nxt=0;
		for(int i=1;i<=n;i++)head[i]=0;
		tot=0;
		
	}
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/
