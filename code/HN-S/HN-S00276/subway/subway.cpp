#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=2e4+5,N=3e5+5;
int c,n,m,d,Q,w[M],k[505],a[505][M],t[505][M],ans,dis[M];
bool vis[M];
int G[405][50005];
struct node{
	int v,w;
	bool operator<(const node &rh)const{
		return w<rh.w;//从小到大 
	}
};
void dij(int s,int t){
	priority_queue<node> q;
	q.push({s,0});
	for(int i=1;i<=m;++i)dis[i]=1e18;
	dis[s]=0;
	while(q.size()){
		node f=q.top();q.pop();
		int u=f.v;
		if(vis[u])continue;
		vis[u]=1;
		for(int tmp=1;tmp<=m+n*n+n;++tmp){
			if(G[u][tmp]==-0x3f)continue;
			if(dis[tmp]>dis[u]+G[u][tmp]){
				dis[tmp]=dis[u]+G[u][tmp];
				q.push({tmp,dis[tmp]});
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	memset(G,-0x3f,sizeof(G));
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			G[i][m+(i-1)*n+j]=0;
			G[m+(i-1)*n+j][i]=0;
		}
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			cin>>a[i][j]>>t[i][j];
			G[a[i][j]][m+(a[i][j]-1)*n+i]=G[m+(a[i][j]-1)*n+i][a[i][j]]=t[i][j];
			if(j>=2){
				G[m+(a[i][j-1]-1)*n+i][m+(a[i][j]-1)*n+i]=G[m+(a[i][j]-1)*n+i][m+(a[i][j-1]-1)*n+i]=0;
			}
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		dij(x,y);
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
