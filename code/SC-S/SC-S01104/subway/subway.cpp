#include<bits/stdc++.h>
using namespace std;
const int N=5e5+505,M=2e6+6;
int c,m,n,d,ask,w[N],k,a,t,x,y;
int head[N],nxt[M],to[M],wei[M],cnt=-1; 
void add(int u,int v,int w){
	cnt++;
	nxt[cnt]=head[u];
	to[cnt]=v;
	wei[cnt]=w;
	head[u]=cnt;
}
struct ndd{
	int id;
	long long dist;
	bool operator<(const ndd &op)const{
		return dist>op.dist;
	}
}tmp;
long long dis[N],vis[N];
priority_queue<ndd> q;
void dij(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push({s,0});
	while(q.size()){
		tmp=q.top();
		q.pop();
		int u=tmp.id;
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=head[u];i!=-1;i=nxt[i]){
			if(dis[to[i]]>dis[u]+wei[i]){
				dis[to[i]]=dis[u]+wei[i];
				if(!vis[to[i]]) q.push({to[i],dis[to[i]]});
			}
		} 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&ask);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a,&t);
			add(a,i+m,t);
			add(i+m,a,t);
		}
	}
	while(ask--){
		scanf("%d%d",&x,&y);
		dij(x);
	//	cout<<dis[y]<<'\n';
		printf("%lld\n",dis[y]+w[x]+w[y]);
	}
	return 0;
} 
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/