#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N=512345,Nd=200023,E=2512345;

int a[N];
int sum[N],w[N],cnt;

int idx=0,h[Nd],to[E],ew[E],nx[E];
void add(int u,int v,int w){
	idx++;
	to[idx]=v;
	ew[idx]=w;
	nx[idx]=h[u];
	h[u]=idx;
}
int dis[Nd],vis[Nd];

void dijkstra(int s){
	priority_queue<PII,vector<PII>,greater<PII> >q;
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	memset(vis,0,sizeof vis);
	q.push(PII({0,s}));
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u]!=0)continue;
		vis[u]=1;
		for(int i=h[u];i;i=nx[i]){
			int v=to[i];
			if(dis[v]>dis[u]+ew[i]){
				dis[v]=dis[u]+ew[i];
				if(!vis[v]){
					q.push(PII({dis[v],v}));
				}
			}
		}
	}
}
int quy(int u,int v){
	dijkstra(u);
	return dis[v];
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,d,q;
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int ltx=0;
		for(int i=1;i<=k;i++){
			int x,y;
			cin>>x>>y;
			cnt++;
			add(x,m+cnt,y);
			add(m+cnt,x,y);
			if(ltx!=0)
			add(ltx,m+cnt,0);
			ltx=m+cnt;
		}
	}for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		
		cout<<quy(x,y)+w[x]+w[y]<<'\n';
	}
	return 0;
}