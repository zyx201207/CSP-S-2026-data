#include<bits/stdc++.h>
using namespace std;
int y[100010],x[100010],c,n,m,d,p,w[200000],k[510],a[510][510],t[510][510];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int y[100010],x[100010],c,n,m,d,p,w[200000],k[510],a[510][510],t[510][510],z[501][510];
	memset(z,0,sizeof(z));
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=p;i++)
	{
		cin>>x[i]>>y[i];
	}
	cout<<w[1]+t[2][n]+t[1][1]+w[n];
	return 0;
 } 
