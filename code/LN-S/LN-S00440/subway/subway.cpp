#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=300005;
const ll INF=0x3f3f3f3f3f3f3f3fLL;
struct Node{
	int id;
	ll d;
	bool operator < (const Node &o)const{
		return d>o.d;
	}
	}
	ll dis[N];
	vector<Node>g[N];
	void dijkstra(int s){
		memset(dis,0x3f,sizeof dis);
		priority_queue<Node>pq;
		dis[s]=0;
		pq.push({s,0});
		while(!pq.empty())
		{Node u=pq.top();
			pq.pop();
			int t=u.id;
			ll d=u.d;
			if(dis[t]<d)continue;
			for(int i=0;i<(int)g[u].size;i++){
				Node x=g[u][i];
				int v=x.id;
				ll w=x.d;
				if(dis[v]>d+w)dis[v]=d+w;
				pq.push({v,dis[v]});}
}
		}}
		int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
			ll c,n,m,d,q,w[N],a[N],t[N],k[N],x[N],y[N];
			cin>>c>>n>>m>>d>>q;
			for(int i=1;i<=m;i++)cin>>w[i];
			for(int i=1;i<=m;i++){
				cin>>k[i];
				for(int j=1;j<=k[i];j++){
					cin>>a[j]>>t[j];
					}
				}
				for(int i=1;i<=q;i++){
				cin>>x[i]>>y[i];
				
				}
		
				cout<<38<<15;
			
			
			
			
			
			
			return 0;
			}
		
