#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=5e5+5,INF=INT_MAX;
int c,n,m,d,q,w[N],k[105],vis[N],maps[N][105];
bool dis[N][105];
vector<pii> e[105],g[N];
struct node{int x,y,num,ans;}p[N];
struct Node{
    int d,dian,xian;
    bool operator<(const Node &tmp)const{
    	return tmp.d>d;
	}
};
bool cmp1(node x,node y){return x.x<y.x;}
bool cmp2(node x,node y){return x.num<y.num;}
void dijkstra(int s){
	priority_queue<Node> pq;
	fill(dis,dis+m+1,false);
	fill(vis,vis+m+1,INF);
	vis[s]=0;
	pq.push({0,s,g[s][0].first});
	while(!pq.empty()){
		Node cur=pq.top();pq.pop();
		int u=cur.dian,r=cur.xian;
		if(dis[u][r]) continue;
		dis[u][r]=true;
		for(auto &ed:e[r]){
			int v=ed.first,w=ed.second;
			if(vis[u]+w<vis[v]) vis[v]=vis[u]+w,pq.push({vis[v],v,r});
		}
		for(auto &ed:g[u]){
			int v=ed.first,w=ed.second;
			if(v==r) continue;
		    if(vis[u]+w+maps[u][r]<vis[u]) vis[u]=vis[u]+w+maps[u][r],pq.push({vis[u],u,v});
		}
	}                                                                             
}
int main(){
    freopen("subway1.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
    	cin>>k[i];
    	for(int j=1;j<=k[i];j++){
    		int shu,ru;cin>>shu>>ru;
    		e[i].push_back({shu,ru});
    		g[shu].push_back({i,ru});
    		maps[shu][i]=ru;
		}
	}
	for(int i=1;i<=q;i++) cin>>p[i].x>>p[i].y,p[i].num=i;
	sort(p+1,p+q+1,cmp1);
	for(int i=1;i<=q;i++){
		dijkstra(p[i].x);
		p[i].ans=vis[p[i].y]+w[p[i].x]+w[p[i].y];
		while(p[i].x==p[i+1].x) i++,p[i].ans=vis[p[i].y]+w[p[i].x]+w[p[i].y];
	}
	sort(p+1,p+q+1,cmp2);
	for(int i=1;i<=q;i++) cout<<p[i].ans<<"\n";
    return 0;
}