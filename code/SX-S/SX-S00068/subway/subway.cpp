#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,v[500005],x[100005],y[100005],k[505][10005],t[505][10005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>v[i];
	}
	int tem[10005];
	for(int i=1;i<=n;i++)
	{
		cin>>tem[i];
		for(int j=1;j<=tem[i];j++)
		{
			cin>>k[i][j]>>t[i][j];
		}
	}
	for(int kk=1;kk<=q;kk++)
	{
		cin>>x[kk]>>y[kk];
		int qx[10005],wx[10005];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=tem[i];j++)
			{
				if(k[i][j]==x[i])  qx[i]++;
				if(k[i][j]==y[i])  wx[i]++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(qx[i]>=1&&wx[i]>=1) 
			{
				cout<1;
			}
		}
	}
	return 0;
}
