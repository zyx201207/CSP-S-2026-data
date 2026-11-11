#include<bits/stdc++.h>
#define N 500050
#define ll long long
using namespace std;
int c,n,m,d,Q;
ll dis[2*N];
int vis[2*N],w[N];
priority_queue<ll,vector<ll>,greater<ll> > q;
struct edge{
	int nxt;
	int to;
	ll dis;
}s[2*N];
int he[2*N],cnt;
void add(int u,int v,int w){
	cnt++;
	s[cnt].nxt=he[u];
	s[cnt].to=v;
	s[cnt].dis=w;
	he[u]=cnt;
}
void dijkstra(int u){
	for(int i=1;i<=m+n;i++){
		dis[i]=1e9+1;
		vis[i]=0;	
	}
	dis[u]=0;
	q.push(u);
	while(!q.empty()){
		int x=q.top();
		q.pop();
		if(vis[x]==1) continue;
		vis[x]=1;
		for(int i=he[x];i;i=s[i].nxt){
			int y=s[i].to;
			if(dis[y]>dis[x]+s[i].dis){
				dis[y]=dis[x]+s[i].dis;
				if(vis[y]==0){
					q.push(y);
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			add(a,m+i,t);
			add(m+i,a,t);
		}
	}
	for(int i=1;i<=Q;i++){
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<dis[y]+w[x]+w[y]<<endl;
	}
}
