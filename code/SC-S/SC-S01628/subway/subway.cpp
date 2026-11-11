#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
int c,n,m,d,p;
int w[N];
int k,a[N],t[N];
int x,y;

int head[N],cnt,dis[N],vis[N];
struct Edge{
	int next,to,dis;
}eg[N<<1];
void add(int from,int to,int dis){
	eg[++cnt].next=head[from];
	eg[cnt].dis=dis;
	eg[cnt].to=to;
	head[from]=cnt;
}
void dij(int s){
	priority_queue<pair<int,int> > q;
	q.push(make_pair(0,s));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(vis[x]==1) continue;
		vis[x]=1;
		for(int i=head[x];i;i=eg[i].next){
			int y=eg[i].to;
			int z=eg[i].dis;
			if(dis[y]>dis[x]+z)
				dis[y]=dis[x]+z;
			q.push(make_pair(dis[y],y));
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			add(a[j],a[j],t[j]);
		}
		for(int j=1;j<=k;j++)
			add(a[j],a[j+1],0);
	}
	for(int i=1;i<=p;i++){
		cin>>x>>y;
		dij(x);
		cout<<dis[y]<<"\n";
	}
	return 0;
}