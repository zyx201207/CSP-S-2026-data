#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[1000005],v[1000005],head[1000005],tot,vis[1000005],fa[1000005],dis[1000005],d[1000005],zong,vis2[1000005],ans=1e9;
struct Num{
	int to,nxt;
}a[2000005];
void add(int u,int v){
	a[++tot].to=v;
	a[tot].nxt=head[u];
	head[u]=tot;
}
int Get(int x){
	if(fa[x]!=x){
		fa[x]=Get(fa[x]);
	}
	return fa[x];
}
void merge(int x,int y){
	int fx=Get(x),fy=Get(y);
	if(fx!=fy){
		fa[fx]=fy;
		zong--;
	}
}
void dfs2(int x){
	for(int i=head[x];i;i=a[i].nxt){
		int to=a[i].to;
		if(vis2[to]) continue;
		vis2[to]=1;
		dis[to]=dis[x]+1;
		dfs2(to);
	}
}
void dfs(int x,int now){
	if(now+(n-x+1)<k||now>k) return ;
	if(x>n){
		zong=k;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<n;i++){
			if(vis[u[i]]&&vis[v[i]]){
				merge(u[i],v[i]);
			}
		}
		if(zong<=2){
			int r=-1e9;
			for(int i=1;i<=n;i++){
				if(vis[i]){
					d[i]=0;
					r=max(r,d[i]);
					continue;
				}
				d[i]=1e9;
				for(int j=1;j<=n;j++){
					vis2[j]=0;
				}
				dis[i]=0;
				vis2[i]=1;
				dfs2(i);
				for(int j=1;j<=n;j++){
					if(vis[j]) d[i]=min(d[i],dis[j]);
				}
				r=max(r,d[i]);
			}
			ans=min(ans,r);
		}
		return ;
	}
	vis[x]=1;
	dfs(x+1,now+1);
	vis[x]=0;
	dfs(x+1,now);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans=1e9;
		tot=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) head[i]=0;
		for(int i=1;i<n;i++){
			scanf("%d%d",&u[i],&v[i]);
			add(u[i],v[i]);
			add(v[i],u[i]);
		}
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}

