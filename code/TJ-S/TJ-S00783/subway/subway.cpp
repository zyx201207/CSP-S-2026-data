#include<bits/stdc++.h>
using namespace std;
int c,n,m,us,q,w[5002],a[507][5002],t[505][5002],tot,ans;
int d[5002][5002];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>us>>q;

	for(int i=1;i<=m;++i)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>tot;
		for(int j=1;j<=tot;j++)
		{
			cin>>a[i][j]>>t[i][j];	
		}
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=m;i++)	d[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=tot;j++){
			for(int k=j+1;k<=tot;k++)
				d[a[i][j]][a[i][k]]=d[a[i][k]][a[i][j]]=min(d[a[i][k]][a[i][j]],t[i][k]+t[i][j]);
		}
	}
	for(int k=1;k<=m;k++)
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	while(q--){
		int x1,y1;
		cin>>x1>>y1;
		cout<<d[x1][y1]+w[x1]+w[y1]<<endl;
	}
	return 0;
}
