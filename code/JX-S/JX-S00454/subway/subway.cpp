#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500050],k[500050],a[501][48000],t[501][480000],x[500050],y[200050],ans=0;
int main()
{
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++)cin>>x[i]>>y[i];
	for(int i=1;i<=q;i++)cout<<w[i]+t[1][i]<<"\n";
	return 0;
}
