#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[550];
int dis[550],h[550],to[550],val[550],nxt[550];
int cnt=0;
bool vis[550];
int dot[550][500050];
int line[550][500050];
void add(int u,int v,int w){
	to[++cnt]=v;
	val[cnt]=w;
	nxt[cnt]=h[u];
	h[u]=cnt;
}
struct node{
	int v,w;
	bool friend operator<(node a,node b){
		return a.w>b.w;
	}
}t;
priority_queue <node> qq;
void dij(int s){
	for(int i=1;i<=n;i++)dis[i]=0;
	dis[s]=0;
	vis[s]=true;
	t.v=s;
	t.w=0;
	while(!qq.empty()){
		int u=qq.top().v;
		qq.pop();
		if(vis[u])continue;
		else vis[u]=true;
		for(int i=h[u];i;i=nxt[i]){
			if(dis[to[i]]>(long long)dis[u]+val[i]){
				dis[to[i]]=dis[u]+val[i];
				t.v=to[i];
				t.w=dis[to[i]];
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway,out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int passer;
		scanf("%d",&passer);
		for(int j=1;j<=passer;j++){
			int a,b;
			scanf("%d%d",&a,&b);
			line[i][j]=a;
			dot[i][j]=b;
		}
		for(int j=2;j<=passer;j++){
			add(line[i][j-1],line[i][j],dot[i][j-1]);
			add(line[i][j],line[i][j-1],dot[i][j-1]);
		}
	}
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		dij(l);
		printf("%d\n",dis[r]);
	}
	return 0;
}