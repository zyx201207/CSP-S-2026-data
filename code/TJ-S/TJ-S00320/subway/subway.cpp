#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[500010];
int edges[2010][2010];
int ans[2010][2010];
void floyd(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				ans[i][j]=min(edges[i][j],edges[i][k]+edges[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			edges[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int u,w;
		cin>>u>>w;
		edges[i][u]=w;
		edges[u][i]=a[i];
	}
	floyd();
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		cout<<ans[l][r]<<endl;
	}
	return 0;
}
