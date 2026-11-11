#include<bits/stdc++.h> 
using namespace std;
long long w[1000000010],a[500010],t[500010],x[100010],y[100010];
int min1,b;
int xy[100010][100010],xy1[100010][100010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++)
		{
			for(int l=j+1;l<=k;l++)
			{
				if(xy1[a[j]][a[l]]==0)
				{
					xy1[a[j]][a[l]]=1;
					if(xy[a[j]][a[l]]>t[a[j]]+t[a[l]])
					{
						xy[a[j]][a[l]]=t[a[j]]+t[a[l]];
					}
				}
			}
		}
		for(int j=1;j<=k;j++)
		{
			for(int l=j+1;l<=k;l++)
			{
				xy1[a[j]][a[l]]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(a[i]>a[j])
			{
				xy[a[j]][a[i]]=xy[a[i]][a[j]];
				xy[a[i]][a[j]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			for(int ij=i;j<=m;j++)
			{
				if(ij!=i&&ij!=j&&xy[i][j]>xy[i][ij]+xy[ij][j]&&xy[i][ij]!=0&&xy[ij][j]!=0)
				{
					xy[i][j]=xy[i][ij]+xy[ij][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++)
	{
		b=w[x[i]]+w[y[i]]+xy[x[i]][y[i]];
		cout<<b<<endl;
	}
	return 0;
}
