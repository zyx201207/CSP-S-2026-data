#include<bits/stdc++.h>
using namespace std;
int c,n,m,dd,q,w[500005],k[505],a[505][505],t[505][505],d[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>q;
	memset(d,0x3f3f3f3f,sizeof(d));
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++){
			for(int y=j+1;y<=k[i];y++){
				d[a[i][j]][a[i][y]]=min(d[a[i][j]][a[i][y]],t[i][j]+t[i][y]);
				d[y][j]=d[j][y];
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				if(d[i][k]==0x3f3f3f3f||d[k][j]==0x3f3f3f3f) continue;
				if(d[i][j]==0x3f3f3f3f){
					d[i][j]=d[i][k]+d[k][j];
				}
				else d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			d[i][j]=d[i][j]+w[i]+w[j];
		}
	}
	for(int i=1;i<=q;i++){
		int xx,yy;
		cin>>xx>>yy;
		cout<<d[xx][yy]<<endl;
	}
	return 0;
}
