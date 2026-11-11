#include <bits/stdc++.h>
using namespace std;
long long w[5005],a[5005][5005],t[5005][5005],k[505],x[5005],y[5005];
bool flag=false;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
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
	for(int p=1;p<=q;p++)
	{
		long long z=0,bj=0,bk=0,bl=0;
		z+=w[x[p]]+w[y[p]];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k[i];j++)
			{
				if(a[i][j]==x[p])
				{
					z+=t[i][j];
					bj=i;
				}
				if(a[i][j]==y[p])
				{
					z+=t[i][j];
					bk=i;
					bl=j;
					if(bj==i)
					{
						cout<<t<<endl;
						flag=true;
					}
					break;
				}
			}
		}
		if(flag==false)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=k[i];j++)
				{
					if(a[bj][j]==y[p])
					{
						z+=(t[bj][j]+t[bk][bl]);
						break;
					}
				}
			}
			cout<<z+10<<endl;
		}
	}
	return 0;
}
