#include <bits/stdc++.h>
using namespace std;
struct s{
	int v,w;
};
int c,n,m,d,q1,w[500001],g[501][501];
vector<int>v[501][501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i!=j) g[i][j]=1e9;	
		}
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[i][a]=g[a][i]=t;
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j) continue;
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				if(g[i][j]==g[i][k]+g[k][j]) v[i][j].push_back(k);
			}
		}
	}
	while(q1--){
		int x,y,ans=0;
		cin>>x>>y;
		int nn=y;
		while(nn!=x){
			ans+=g[v[x][nn][0]][v[x][nn][0]];
			nn=v[x][nn][0];
		}
		cout<<ans+g[x][x]+g[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}

