#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+5;
struct node{
	int to,nxt;ll w;
}e[2*M];
int c,n,m,d,Q,cnt,head[M];
ll W[M],dist[205][80005],f[M];
bool fl[205][80005],vis[M];
void add(int u,int v,ll w){
	e[++cnt].to=v;
	e[cnt].w=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
void dij(int st){
	priority_queue<pair<ll,int> > q;
	dist[st][st]=0;
	fl[st][st]=1;
	q.push({0,st});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(!fl[st][v]&&dist[st][v]>dist[st][u]+e[i].w){
				dist[st][v]=dist[st][u]+e[i].w;
				fl[st][v]=1;
				q.push({-dist[st][v],v});
			}
		}
	}
}
void dij2(int st){
	memset(f,0x3f3f3f3f,sizeof f);
	memset(vis,0,sizeof vis);
	priority_queue<pair<ll,int> > q;
	f[st]=0;
	vis[st]=1;
	q.push({0,st});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(!vis[v]&&f[v]>f[u]+e[i].w){
				f[v]=f[u]+e[i].w;
				vis[v]=1;
				q.push({-f[v],v});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>W[i];
	for(int i=2;i<=n+1;i++){
		int lenK,x,lst;ll y;
		cin>>lenK;
		for(int j=1;j<=lenK;j++){
			cin>>x>>y;
			if(j>1) add(i*m+x,i*m+lst,0),add(i*m+lst,i*m+x,0);
			add(x,i*m+x,y),add(i*m+x,x,y);
			lst=x;
		}
	}
	if(n<=200&&m<=400){
		memset(dist,0x3f3f3f3f,sizeof dist);
		for(int i=1;i<=m;i++) dij(i);
	}
	ll ans;
	for(int qq=1,x,y;qq<=Q;qq++){
		cin>>x>>y;
		if(n<=200&&m<=400) ans=W[x]+W[y]+dist[x][y];
		else{
			dij2(x);
			ans=W[x]+W[y]+f[y];
		}
		cout<<ans<<'\n';
	}
	return 0;
}