#include<bits/stdc++.h>
using namespace std;
const int N=2010;
int c,n,m,q,w[N],d[N][N],t[N][N],x,y,k,z;
vector<int>e[N];
vector<int>st[N];
void floyd(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				d[j][i]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
void dfs(int u){
	int v;
	for(int V=0;V<st[u].size();V++){
		v=st[u][V];
		for(int i=0;i<e[v].size();i++){
			int ne=e[v][i];
			d[u][ne]=min(d[u][ne],t[u][v]+t[ne][v]);
			d[ne][u]=min(d[u][ne],t[u][v]+t[ne][v]);
		}
	}
}
void link(int i){
	for(int j=1;j<e[i].size();j++){
		for(int k=j+1;k<e[i].size();k++){
			int u=e[i][j],v=e[i][k];
			d[u][v]=min(d[u][v],t[u][i]+t[v][i]);
			d[v][u]=min(d[u][v],t[u][i]+t[v][i]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(d,0x3f,sizeof d);
	scanf("%d%d%d%d%d",&c,&n,&m,&c,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&x);
			scanf("%d",&t[x][i]);
			st[x].push_back(i);
			e[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++)link(i);
	for(int i=1;i<=m;i++){
		dfs(i);
	}
	floyd();
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",w[x]+w[y]+d[x][y]);
	}
	return 0;
}
