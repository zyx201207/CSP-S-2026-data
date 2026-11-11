#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int c,n,m,d,q;
int tot=0;
vector<pair<int,int>> edge[1500001];
int kou[500001],ting[500001];
long long dist[1500001];
inline long long dijstra(int x,int y){
	x=kou[x],y=kou[y];
	//cout<<x<<" "<<y<<"\n";
	bool vis[1500001];
	rep(i,1,tot)
		dist[i]=-1,vis[i]=false;
	priority_queue<pair<long long,int>> q;
	dist[x]=0;
	q.push(make_pair(0,x));
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u]=true;
		//cout<<u<<"\n";
		for(auto v0:edge[u]){
			//cout<<"ooo\n";
			int v=v0.first,z=v0.second;
			if(vis[v])
				continue;
			//cout<<"DEBUG "<<v<<" "<<z<<"\n";
			//cout<<"DEBUG "<<dist[v]<<" "<<dist[u]+z<<"\n";
			if(dist[v]==-1||dist[v]>dist[u]+z){
				dist[v]=dist[u]+z;
				q.push(make_pair(-dist[v],v));
			}
		}
	}
	return dist[y];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m){
		int w;
		cin>>w;
		tot++;
		kou[i]=tot;
		edge[kou[i]].push_back(make_pair(++tot,w)),edge[tot].push_back(make_pair(kou[i],w));
		ting[i]=tot;
		//cout<<kou[i]<<" "<<ting[i]<<"\n";
	}
	rep(i,1,n){
		int k;
		cin>>k;
		int tmp=-1;
		rep(j,1,k){
			int a,t;
			cin>>a>>t;
			edge[ting[a]].push_back(make_pair(++tot,t)),edge[tot].push_back(make_pair(ting[a],t));
			if(tmp!=-1){
				edge[tot].push_back(make_pair(tmp,0)),edge[tmp].push_back(make_pair(tot,0));
			}
			tmp=tot;
		}
	}
	/*rep(i,1,tot){
		cout<<i<<"\n";
		for(auto j:edge[i])
			cout<<j.first<<" "<<j.second<<"\n";
	}*/
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dijstra(x,y)<<"\n";
	}
	return 0;
}
