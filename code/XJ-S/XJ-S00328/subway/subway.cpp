#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+505;
struct edge{
	int v,w;
};
struct node{
	int idx,dis;
	friend bool operator<(const node &q,const node &p){
		return q.dis>p.dis;
	}
};
struct need{
	int u,v;
	int id;
}cnt[100005];
int dis[N],vis[N],val[N],ans[100005];
int c,n,m,d,q;
vector<edge> e[N];
void dij(int s){
	priority_queue<node> q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push((node){s,dis[s]});
	while(!q.empty()){
		node t=q.top();
		q.pop();
		int u=t.idx;
		if(vis[u]==1)	continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			edge now=e[u][i];
			int v=now.v,w=now.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push((node){v,dis[v]});
			}
		}
	}
}
bool cmp(need x,need y){
	return x.u<y.u;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>val[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int u=m+i;
		for(int j=1;j<=k;j++){
			int w,v;
			cin>>v>>w;
			e[u].push_back((edge){v,w}); 
			e[v].push_back((edge){u,w}); 
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		if(u>v)	swap(u,v);
		cnt[i]=(need){u,v,i};
	}
	sort(cnt+1,cnt+q+1,cmp);
	for(int i=1;i<=q;i++){
		int u=cnt[i].u,v=cnt[i].v,id=cnt[i].id;
		if(u==cnt[i-1].u)	ans[id]=dis[v]+val[u]+val[v];
		else{
			dij(u);
			ans[id]=dis[v]+val[u]+val[v];
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
} 
