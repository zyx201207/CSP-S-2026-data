#include<bits/stdc++.h>
#define IO freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
using namespace std;
typedef long long ll;
typedef struct edge{
	int v;
	int w;
	int next;
}edge;
typedef struct quest{
	int v;
	ll ans;
	int id;
}quest;
typedef struct node{
	int now;
	ll dist;
	friend bool operator>(node a,node b){
		return a.dist>b.dist;
	}
}node;
int cntn=0;
int tot=0;
int c,n,m,d,q;
int tail;
int W[500010];
int head[500510];
ll dis[500510];
edge G[1000010];
bool vis[500510];
bool ask[500510];
quest ans[100010];
vector<quest>que[500010];
void add(int u,int v,int w){
	G[++tail]=(edge){v,w,head[u]};
	head[u]=tail;
}
void work(int s){
	for(int i=1;i<=m+n+10;i++)
		dis[i]=0x7f7f7f7f7f7f7f7f,
		vis[i]=0,
		ask[i]=0;
	for(quest &x:que[s])
		ask[x.v]=1;
	int ned=que[s].size();
	priority_queue<node,vector<node>,greater<node>>q;
	q.push((node){s,0});
	dis[s]=0;
	while(ned&&!q.empty()){
		node gt=q.top();
		q.pop();
//		printf("i've got into %d\n",gt.now);
		if(vis[gt.now])continue;
		vis[gt.now]=1;
		if(ask[gt.now])ned--;
		int &u=gt.now;
		for(int ed=head[u];ed!=0;ed=G[ed].next){
			if(vis[G[ed].v])continue;
			if(dis[G[ed].v]>dis[u]+G[ed].w){
				dis[G[ed].v]=dis[u]+G[ed].w;
				q.push((node){G[ed].v,dis[G[ed].v]});
			}
		}
	}
	for(quest &x:que[s]){
		x.ans=dis[x.v];
		ans[++tot]=x;
		ans[tot].ans+=W[s]+W[x.v];
	}
}
signed main(){
	IO;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&W[i]);
	cntn=m;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		cntn++;
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%d%d",&a,&t);
			add(cntn,a,t);
			add(a,cntn,t);
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		que[u].push_back((quest){v,-1,i});
	}
	for(int i=1;i<=m;i++){
		if(que[i].size()){
			work(i);
		}
	}
	sort(&ans[1],&ans[tot+1],[](quest &a,quest &b){
		return a.id<b.id;
	});
	for(int i=1;i<=q;i++){
		printf("%lld\n",ans[i].ans);
	}
	return 0;
}