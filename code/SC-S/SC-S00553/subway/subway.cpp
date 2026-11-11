#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e3;
int c,n,m,d,q;
//c:测试点编号,n:地铁线路数,m:地铁站数,d:每个地铁站最多被几条线路经过,q:以及出行计划数
vector<int>w;//从每个地铁站的地铁口走到站厅需要的时间
int T[MAXN][MAXN];//两个地铁站之间相互到达的最短时间
int G[MAXN][MAXN];//G[i][j]=k:从i到j需要k
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	w.resize(m+4);
	for(int i=1;i<=m;i++) cin>>w[i];
	memset(T,-1,sizeof(T));
	memset(G,-1,sizeof(G));
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k&&cin>>a>>t;j++)
			G[i][a]=t;
	}
	for(int u=1;u<=m;u++){
		for(int v=1;v<=m;v++){
			if(G[u][v]==-1) continue;
			T[u][v]=G[u][u]+G[u][v];
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++){
				if(T[i][k]==-1||T[k][j]==-1) continue;
				if(T[i][j]==-1) T[i][j]=T[i][k]+T[k][j];
				else T[i][j]=min(T[i][j],T[i][k]+T[k][j]);
			}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x>y) swap(x,y);
		cout<<w[x]+w[y]+T[x][y]<<'\n';
	}
	return 0;
}