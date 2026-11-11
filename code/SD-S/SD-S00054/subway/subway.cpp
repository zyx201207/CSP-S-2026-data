#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q1;
struct node{
	int v,w;
};
vector<node> ve[20000005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int dis[20000005],vis[20000005];
void dijkstra(int x){
	memset(dis,0x3f,(d*2*m)*sizeof(int));
	memset(vis,0,(d*2*m)*sizeof(int));
	dis[x]=0;
	q.push({0,x});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		vis[u]=1;
		for(auto edg:ve[u]){
			int v=edg.v;
			int w=edg.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		ve[i].push_back({m+i,w});
		ve[m+i].push_back({i,w});
	}
	int a1=0,t1=0,cnt1=1;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			ve[m+a].push_back({2*m+cnt1,t});
			ve[2*m+cnt1].push_back({m+a,t});
			if(j!=1){
				ve[2*m+cnt1-1].push_back({2*m+cnt1,0});
				ve[2*m+cnt1].push_back({2*m+cnt1-1,0});
			}
			cnt1++;
		}
	}
	for(int i=1;i<=q1;i++){
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<dis[y]<<"\n";
	}
	return 0;
}
