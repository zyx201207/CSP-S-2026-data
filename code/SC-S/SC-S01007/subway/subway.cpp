#include<bits/stdc++.h>
using namespace std;
const int M=5000500,N=1e9+100;
long long int c,n,m,d,q;
long long int w[M],a[N][N],t[N][N],k[N],x[N],y[N];
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>v>>m>>d>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
		cin>>x[i]>>y[i];
	for(int i=0;i<=q;i++)
	{
		cout<<w[x[i]]+[w[y[i]]]+2*t[1][1]<<" ";
	} 
	return 0;
}