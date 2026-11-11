#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#define ll long long
using namespace std;
const int N=5010;
int c,T,n,k,u,v,ans=11451419,cnt;
int dis[N][3];
int tot,ver[N<<1],nxt[N<<1],head[N],col[N];
bool vis[N][3],viss[N];
void add(int x,int y){
	ver[++tot]=y,nxt[tot]=head[x],head[x]=tot;
}
void clr(){
	memset(ver,0,sizeof(ver));
	memset(nxt,0,sizeof(nxt));
	memset(head,0,sizeof(head));
	tot=0;ans=1145141919;
}
void dfs(int x,int fa){
	if(col[x]||!viss[x])return;
	col[x]=cnt;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];if(y==fa)continue;
		dfs(y,x);
	}
}
void dfs2(int x,int fa,int cl){
	if(vis[x][cl])return;
	vis[x][cl]=1;
	dis[x][cl]=dis[fa][cl]+1;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];if(y==fa)continue;
		dfs2(y,x,cl);
	}
}
void calc(int S){
	cnt=0;int d=0;
	for(int i=1;i<=n;i++)vis[i][1]=vis[i][2]=col[i]=dis[i][1]=dis[i][2]=viss[i]=0;
	for(int i=1;i<=n;i++){
		if((S>>i-1)&1)viss[i]=1;
	}
	for(int i=1;i<=n;i++){
		if((S>>i-1)&1){
			if(!col[i])dfs(i,0);
		}
	}
	if(cnt>2)return;
	for(int i=1;i<=n;i++){
		if(viss[i])dfs2(i,0,col[i]);
	}
	for(int i=1;i<=n;i++){
		if(cnt==1){
			d=max(d,dis[i][1]);
		}else d=max(d,min(dis[i][1],dis[i][2]));
	}
	ans=min(ans,d);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		clr();
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			add(u,v),add(v,u);
		}
		int res=0;
		for(int i=0;i<(1<<n);i++){
			res=0;
			for(int j=0;j<n;j++){
				if((i>>j)&1)res++;
			}
			if(res==k)calc(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
hywhywhywhywhywhywhywhywhywhywhywhywhyw
*/
