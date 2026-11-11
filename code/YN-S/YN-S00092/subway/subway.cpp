#include<bits/stdc++.h>
using namespace std;

#define int long long

const int yc=500;
const int scx=5e5+10;
const int inf=2e9+10;

int c,n,m,d,q;
int w[scx];

int head[scx],tot;
struct node{
	int u,v,w,nt;
}edge[scx<<1];
void add(int u,int v,int w){
	edge[++tot]={u,v,w,head[u]};
	head[u]=tot;
}

struct furina{
	int x,id;
	friend bool operator < (furina a,furina b){
		return a.x>b.x;
	}
}tmp;

bool vis[scx];
int dis[scx];
void dj(int s){
	priority_queue<furina>q;
	memset(vis,false,sizeof vis);
	memset(dis,inf,sizeof dis);
	q.push({0,s});
	dis[s]=0;
	while(!q.empty()){
		tmp=q.top();
		q.pop();
		if(vis[tmp.id])continue;
		vis[tmp.id]=true;
		int u=tmp.id;
		for(int i=head[u];i;i=edge[i].nt){
			int v=edge[i].v;
			int w=edge[i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
//di tie zhang 1 ~ m
//xian lu m+1 ~ m+n

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			int u=a,v=i+m;
			add(u,v,t);
			add(v,u,t);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dj(x);
		cout<<dis[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
