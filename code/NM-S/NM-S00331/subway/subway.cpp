#include <bits/stdc++.h>
using namespace std;
const int N=500005,M=2000005,INF=0x3f3f3f3f;
int idx;
int head[N],vis[N],dis[N];
struct Edge{
	int to,wt,next;
}edge[M];
struct Node{
	int id,d;
	bool operator < (const Node &x) const{
		return d>x.d;
	}
};
void add(int u,int v,int w){
	edge[idx].to=v;
	edge[idx].wt=w;
	edge[idx].next=head[u];
	head[u]=idx++;
}
void dij(int be,int cnt){
	for(int i=1;i<=cnt;i++){
		vis[i]=0;
		dis[i]=INF;
	}
	priority_queue<Node>q;
	dis[be]=0;
	vis[be]=1;
	q.push({be,0});
	while(!q.empty()){
		int u=q.top().id;
		q.pop();
		vis[u]=1;
		for(int i=head[u];i!=-1;i=edge[i].next){
			int v=edge[i].to;
			int w=edge[i].wt;
			if(vis[v]) continue;
			if(dis[u]+w<=dis[v]){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}

}
int main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	memset(head,-1,sizeof(head));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		add(i,i+m,w);
		add(i+m,i,w);
	}
	int cnt=m*2+1;
	bool topp=1;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			if(j==2) topp=0;
			add(cnt,x+m,t);
			add(x+m,cnt,t);
			if(!topp){
				add(cnt,cnt-1,0);
				add(cnt-1,cnt,0);
			}
			cnt++;
		}
		topp=1;
	}
	for(int i=1;i<=cnt-1;i++){
		cout<<head[i]<<" ";
	}
	while(q--){
		int be,fi;
		cin>>be>>fi;
		dij(be,cnt-1);
		cout<<dis[fi]<<endl;
	}
	return 0;
}
