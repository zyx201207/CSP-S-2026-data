#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m+1],k[n+1],a[n+1][m+1],t[n+1][m+1],f[m+1][m+1];
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++)f[i][i]=0;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int o=1;o<=k[i];o++){
			for(int p=1;p<=k[i];p++){
				f[a[i][o]][a[i][p]]=f[a[i][p]][a[i][o]]=min(f[a[i][o]][a[i][p]],t[i][o]+t[i][p]);
			}
		}
	}
	for(int l=1;l<=m;l++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=f[j][i]=min(f[i][j],f[i][l]+f[l][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+f[x][y]+w[y]<<endl;
	}
	return 0;
}
