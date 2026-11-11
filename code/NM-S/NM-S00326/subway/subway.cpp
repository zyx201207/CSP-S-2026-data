#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[30000],k[30000],a[300][300],t[300][300],x[30000],y[30000];
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>k[i];
		for(int j=0;j<2*k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<q;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<q;i++)
	{
		int ans=w[x[i]]+t[x[i]][x[i]]+t[x[i]][y[i]]+w[y[i]];
		cout<<ans;
	}
	return 0;
}
