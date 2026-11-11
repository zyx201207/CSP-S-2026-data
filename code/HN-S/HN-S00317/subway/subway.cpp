#include<bits/stdc++.h>
using namespace std;
const int N=500010,M=510;
int c,n,m,d,q;
int w[N],a[N],t[N],dis[N*10];
bool vis[N];
struct node{
	int nxt,to,val;
}root[N*10];
int head[N*10],tot;
void add(int u,int v,int w){
	root[++tot].nxt=head[u];
	root[tot].to=v;
	root[tot].val=w;
	head[u]=tot;
}
void bfs(int u){
	queue<int> q;
	q.push(u);
	dis[u]=0;
	memset(vis,0,sizeof(vis));
	vis[c]=1;
	while(!q.empty()){
		int c=q.front();
		q.pop();
		vis[c]=0;
		for(int i=head[c];i!=0;i=root[i].nxt){
			int to=root[i].to,val=root[i].val;
			if(dis[c]+val<dis[to]&&!vis[to]){
				dis[to]=dis[c]+val;
				if(!vis[to]){
					q.push(to);
					vis[to]=1;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a[j],&t[j]);
			add(i+N,a[j],t[j]);
			add(a[j],i+N,t[j]);
		}
	}
	for(int i=1,u,v;i<=q;i++){
		memset(dis,127,sizeof(dis));
		scanf("%d%d",&u,&v);
		bfs(u);
		printf("%d\n",dis[v]+w[u]+w[v]);
	}
	return 0;
}
