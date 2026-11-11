#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,u,v;
long long w[500001];
vector<long long>t[501];
vector<int>a[501];
long long k[501];
struct node{
	long long s;
	int nxt;
};
vector<node>edge[500001];
struct question{
	int l,r,id;
};
int cmp(question x,question y){
	return x.l<y.l;
}
question qs[100001];
long long ans[100001];
long long dist[20001],vis[20001];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >qu;
void dijkstra(int st){
	memset(dist,0x3f3f3f3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	qu.push({0,st});
	dist[st]=0;
	while(!qu.empty()){
		long long u=qu.top().second;
		qu.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<edge[u].size();i++){
			if(dist[u]+edge[u][i].s<dist[edge[u][i].nxt]){
				dist[edge[u][i].nxt]=dist[u]+edge[u][i].s;
				qu.push({dist[edge[u][i].nxt],edge[u][i].nxt});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>u>>v;
			a[i].push_back(u);
			t[i].push_back(v);
			for(int at=0;at<j-1;at++){
				edge[a[i][j-1]].push_back({t[i][j-1]+t[i][at],a[i][at]});
				edge[a[i][at]].push_back({t[i][j-1]+t[i][at],a[i][j-1]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qs[i].l>>qs[i].r;
		qs[i].id=i;
	}
	sort(qs+1,qs+1+q,cmp);
	for(int i=1;i<=q;i++){
		if(qs[i].l!=qs[i-1].l){
			dijkstra(qs[i].l);
		}
		ans[qs[i].id]=dist[qs[i].r]+w[qs[i].l]+w[qs[i].r];
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
	return 0;
}