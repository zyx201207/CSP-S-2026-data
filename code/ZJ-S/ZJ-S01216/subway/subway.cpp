#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[500005],a[505][500005],t[505][500005],x[500005],y[500005];
int main()
{
	int num=0;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin >>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin >>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin >>x[i]>>y[i];
		for(int j=x[i];j<=y[i];j++)
		{
			num+=w[j];
		}
		for(int j=1;i<=n;i++)
		{
			if(j>=x[i]&&j<=y[i])
			{
				num+=t[i][j];
			}
		}
	}
	cout<<num;
	
	return 0;
}
