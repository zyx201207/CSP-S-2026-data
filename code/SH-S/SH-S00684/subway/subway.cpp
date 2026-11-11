#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
const int M = 5e5+5;
int c,n,m,D,Q,w[M],ans,d[N][N],a[M],t[M];
struct Node{int u,w;};
vector<Node> g[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>c>>n>>m>>D>>Q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1,k;i<=n;++i){
		cin>>k;
		for(int j=0;j<k;++j){
			cin>>a[j]>>t[j];
			g[a[j]].push_back({i,t[j]});
		}
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1,t,u,v;i<=m;++i){
		for(int a=0;a<g[i].size();++a){
			for(int b=0;b<g[i].size();++b){
				if(a==b) continue;
				t=g[i][a].w+g[i][b].w;
				u=g[i][a].u,v=g[i][b].u;
				if(t<d[u][v])
					d[u][v]=d[v][u]=t;
			}
		}
	}
	for(int i=1;i<=n;++i) d[i][i]=0;
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i){
			if(d[i][k]>=0x3f3f3f3f3f3f3f3f) continue;
			for(int j=1;j<=n;++j){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	while(Q--){
		int x,y;
		cin>>x>>y;
		ans=LLONG_MAX;
		for(int a=0,u,v;a<g[x].size();++a)
			for(int b=0;b<g[y].size();++b){
				u=g[x][a].u,v=g[y][b].u;
				ans=min(ans,d[u][v]+g[x][a].w+g[y][b].w);
			}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
