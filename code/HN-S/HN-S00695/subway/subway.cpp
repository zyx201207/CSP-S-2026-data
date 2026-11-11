#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long w[N];
struct node{
	int to;
	long long v;
};
vector<node>q[N];
long long f[510][510],inf=1e18;
priority_queue<node>Q;
bool vis[510];
int n;
bool operator<(node a,node b){
	return a.v>b.v;
}
void dij(int x){
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++){
		Q.push({i,f[x][i]});
	}
	while(!Q.empty()){
		int u=Q.top().to;
		Q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		if(u<x){
			for(int i=1;i<=n;i++){
				f[x][i]=min(f[x][i],f[x][u]+f[u][i]);
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(f[x][u]+f[u][i]<f[x][i]){
					f[x][i]=f[x][u]+f[u][i];
					Q.push({i,f[x][i]});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,m,d,Q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
	//cout<<c;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x,y;
			scanf("%d%d",&x,&y);
			q[x].push_back({m+i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				f[i][j]=0;
			}
			else{
				f[i][j]=inf;
			}
		}
	}
	for(int i=1;i<=m;i++){
		int tot=q[i].size();
		for(int j=0;j<tot;j++){
			for(int k=j+1;k<tot;k++){
				int u=q[i][j].to-m,v=q[i][k].to-m;
				f[u][v]=min(f[u][v],q[i][j].v+q[i][k].v);
				f[v][u]=f[u][v];
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=min(f[i][j],f[j][i]);
		}
	}
	while(Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=inf;
		for(int i=0;i<q[x].size();i++){
			for(int j=0;j<q[y].size();j++){
				int u=q[x][i].to-m;
				int v=q[y][j].to-m;
				ans=min(ans,f[u][v]+q[x][i].v+q[y][j].v);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}