#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,x,t,y;
int w[100005];
vector<int>e[500005];
long long a[2505][2505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	if(c<=11)
	{
		for(int i=1;i<=m+n;i++)for(int j=1;j<=n+m;j++)a[i][j]=100000000000007;
		for(int i=1;i<=m+n;i++)a[i][i]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				cin>>x>>t;
				a[x][m+i]=a[m+i][x]=t;
			}
		}
		for(int k=1;k<=m+n;k++)
		{
			for(int i=1;i<=m+n;i++)
			{
				for(int j=1;j<=m+n;j++)
				{
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
				}
			}
		}
		for(int i=1;i<=q;i++)
		{
			cin>>x>>y;
			cout<<a[x][y]+w[x]+w[y]<<endl;
		}
	}
	return 0;
}

