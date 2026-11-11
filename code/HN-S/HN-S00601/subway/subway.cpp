#include<bits/stdc++.h>
using namespace std;
int w[500010],k[400];
int a[200][400],t[200][400];
int dis[400][400];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=m;i++)
		for(int ii=1;ii<=m;ii++)
			dis[i][ii]=214748347;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++)
			for(int jj=1;jj<=k[i];jj++)
				if(j!=jj)dis[a[i][j]][a[i][jj]]=t[i][j]+t[i][jj],dis[a[i][jj]][a[i][j]]=t[i][j]+t[i][jj];
	}
	for(int l=1;l<=m;l++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				 dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<endl; 
	}
	return 0;
	
}

