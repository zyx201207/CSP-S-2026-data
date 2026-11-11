#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],dis[1000005],vis[1000005],head[1000005],a[500005],t[500005],toto;
struct node{
	int to,w,next;
}e[1000005];
void add(int u,int v,int w){
	e[toto].to=v;
	e[toto].w=w;
	e[toto].next=head[u];
	head[u]=toto;
	toto++;
}
void SPFA(int x){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	queue<int> q;
	dis[x]=0;
	vis[x]=1;
	q.push(x);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].to;
			int w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					q.push(v);
					vis[v]=1;
				}
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
	memset(head,-1,sizeof(head));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a[j]>>t[j];
		for(int j=1;j<=k;j++) add(500000+i,a[j],t[j]),add(a[j],500000+i,t[j]);
	}
	while(q--){
		long long ans=0;
		int x,y;
		cin>>x>>y;
		ans=w[x]+w[y];
		SPFA(x);
		ans+=dis[y];
		cout<<ans<<"\n";
	}
	return 0;
}
