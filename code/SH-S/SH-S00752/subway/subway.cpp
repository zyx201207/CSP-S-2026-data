#include<bits/stdc++.h>
using namespace std;
#define N 555
#define M 555555
#define D 20
void open(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
struct Edge{int v,w;};
int c,n,m,d,q,w[M],k,u,v,el[M];
long long dis[N][N],ans;
Edge e[M][D];
int main(){
	open("subway");
	memset(dis,0x3f,sizeof(dis));
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>u>>v;
			e[u][el[u]++]={i,v};
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<el[i];j++)
			for(int k=j+1;k<el[i];k++)
				dis[e[i][j].v][e[i][k].v]=dis[e[i][k].v][e[i][j].v]
					=min(dis[e[i][j].v][e[i][k].v],(long long)e[i][j].w+e[i][k].w);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		cin>>u>>v;
		ans=1e18;
		for(int i=0;i<el[u];i++)
			for(int j=0;j<el[v];j++)
				ans=min(ans,e[u][i].w+dis[e[u][i].v][e[v][j].v]+e[v][j].w);
		cout<<ans+w[u]+w[v]<<'\n';
	}
	cout.flush();
}