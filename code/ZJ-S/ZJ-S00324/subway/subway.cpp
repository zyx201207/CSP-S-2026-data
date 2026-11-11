#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,we[N],k1,dis[N],vis[N];
struct node{
	int v,w;
	bool operator<(const node o)const{
		return w>o.w;
	}
};
struct edge{
	int v,w;
};
priority_queue<node> qe;
vector<edge> G[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>we[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		k1+=k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			G[m+i].push_back({v,w});
			G[v].push_back({m+i,w});
		}
	}
	n+=m;
	m=k1;
	while(q--){
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			dis[i]=LLONG_MAX;
			vis[i]=0;
		}
		dis[x]=0;
		qe.push({x,0});
		while(qe.size()){
			node cur=qe.top();
			qe.pop();
			if(vis[cur.v])continue;
			vis[cur.v]=1;
			for(int i=0;i<G[cur.v].size();i++){
				int v=G[cur.v][i].v,w=G[cur.v][i].w;
				if(dis[v]>dis[cur.v]+w){
					dis[v]=dis[cur.v]+w;
					qe.push({v,dis[v]});
				}
			}
		}
		cout<<dis[y]+we[x]+we[y]<<endl;
	}
	return 0;
}
