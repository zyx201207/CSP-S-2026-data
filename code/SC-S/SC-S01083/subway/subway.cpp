#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
int C,n,m,d,q,a[N];
ll dis[N];
bool vis[N];
vector<pair<int,int> >e[N];
void Dijkstra(int s){
	for(int i=1;i<=n;i++){
		vis[i]=false;
		dis[i]=inf;
	}
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
	dis[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(auto p:e[u]){
			int v=p.first,w=p.second;
			if(dis[v]>dis[u]+1LL*w){
				dis[v]=dis[u]+1LL*w;
				q.push(make_pair(dis[v],v));
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
	cin>>C>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		int len;
		cin>>len;
		while(len--){
			int u,w;
			cin>>u>>w;
			e[n+i].push_back(make_pair(u,w));
			e[u].push_back(make_pair(n+i,w));
		}
	}
	n+=m;
	while(q--){
		int u,v;
		cin>>u>>v;
		Dijkstra(u);
		cout<<1LL*a[u]+1LL*a[v]+dis[v]<<'\n';
	}
	return 0; 
}