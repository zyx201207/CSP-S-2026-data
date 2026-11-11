#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[2005],k[505],g[2005][2005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(g,0x3f,sizeof(g));
	for (int i=1;i<=m;i++){
		g[i][i]=0;
	}
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		long long a[2005],t[2005];
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
		}
		for (int j=1;j<=k[i];j++){
			for (int u=1;u<=k[i];u++){
				g[a[j]][a[u]]=min(g[j][u],t[j]+t[u]);
			}
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=1;j<=m;j++){
			for (int k=1;k<=m;k++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=1;j<=m;j++){
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}
	for (int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<g[x][y]<<endl;
		cout<<g[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
