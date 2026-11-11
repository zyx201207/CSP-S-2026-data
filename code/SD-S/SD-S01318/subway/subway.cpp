#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[1000001];
int g[1010][1010];
int a[10001],b[10001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,0x3f,sizeof g);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>a[j]>>b[j];
		}
		for(int j=1;j<=x;j++){
			for(int k=1;k<=x;k++){
				if(j==k) continue;
				g[a[j]][a[k]]=min(g[a[j]][a[k]],b[j]+b[k]);
				g[a[k]][a[j]]=g[a[j]][a[k]];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if(g[i][k]>g[i][j]+g[j][k]){
					g[i][k]=g[i][j]+g[j][k];
				}
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<g[u][v]+w[u]+w[v]<<"\n";
	}
	return 0;
}
