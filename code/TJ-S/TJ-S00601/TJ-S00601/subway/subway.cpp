#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	long long w[m+5],k[n+5],a[392][393],t[392][393],x[q+5],y[q+5];
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
    }
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		
	}
	return 0;
}
