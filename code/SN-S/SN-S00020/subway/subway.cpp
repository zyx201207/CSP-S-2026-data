#include<bits/stdc++.h>
using namespace std;
int c,n,m,D,q,h[505],cnt;
long long w[500005],k[505],d[505];
bool vis[505];
struct edge{
	int next,to,w;
}e[500500];
void aedge(int a,int b,int c){
	e[++cnt].next=h[a];
	e[cnt].to=b;
	e[cnt].w=c;
	h[a]=cnt;
}
struct node{
	long long frist,second;
	friend bool operator <(node a,node b){
		return a.frist<b.frist;
	}
}ma;
priority_queue<node>p;
void dij(int x){
	for(int i=0;i<=505;i++)vis[i]=0,d[i]=INT_MAX;
	d[x]=0;
	ma.frist=0,ma.second=x;
	p.push(ma);
	while(!p.empty()){
		int u=p.top().second;
		p.pop();
		if(vis[u]==1)continue;
		vis[u]=1;
		for(int i=h[u];i;i=e[i].next){
			int v=e[i].to;
			long long w=e[i].w;
			if(d[v]>d[u]+w)d[v]=d[u]+w;
			ma.frist=d[v],ma.second=v;
			p.push(ma);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,f,t;
		cin>>k>>f>>t;
		for(int j=1;j<=k-1;j++){
			int x,y;
			cin>>x>>y;
			aedge(f,x,t+y);
		} 
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long ans=w[x]+w[y];
		dij(x);
		long long tem=d[y];
		dij(y);
		if(tem>=INT_MAX&&d[x]>=INT_MAX)tem=0; 
		cout<<ans+min(tem,d[x])<<endl;		
	}
	return 0;
}
