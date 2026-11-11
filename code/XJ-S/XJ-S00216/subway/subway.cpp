#include<bits/stdc++.h>
using namespace std;
int w[500005],k[505],a[505][505],t[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p,i,j,x,y;
	cin>>c>>n>>m>>d>>p;
	for(i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>k[i];
		for(j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(i=1;i<=p;i++)
	{
		cin>>x>>y;
	}
	for(i=1;i<=p;i++)
	{
		cout<<x+y<<endl;
	}
	return 0;
}
