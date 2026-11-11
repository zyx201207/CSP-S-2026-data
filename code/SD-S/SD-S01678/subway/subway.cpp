#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+505;
const long long INF=1e18;
int c,n,m,d,q;
long long w[maxn];
struct node{
	int to,nxt;
	long long w;
}e[maxn];
int cnt;
int head[maxn];
void add(int u,int v,long long w){
	e[cnt].to=v;
	e[cnt].w=w;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u;
			long long w;
			cin>>u>>w;
			add(u,i+m,w);
			add(i+m,u,w);
		}
	}
	priority_queue<
		pair<long long,int>,
		vector<pair<long long,int> >,
		greater<pair<long long,int> > > pq;
	while(q--){
		int x,y;
		cin>>x>>y;
		while(!pq.empty()){
			pq.pop();
		}
		vector<long long> dist(n+1,INF);
		dist[x]=0;
		pq.push({0,x});
		while(pq.size()){
			long long d=pq.top().first;
			int u=pq.top().second;
			pq.pop();
			if(d>dist[u]) continue;
			for(int i=head[u];i!=-1;i=e[i].nxt){
				int v=e[i].to;
				long long w=e[i].w;
				if(dist[u]+w<dist[v]){
					dist[v]=dist[u]+w;
					pq.push({dist[v],v});
				}
			}
		}
		cout<<dist[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
