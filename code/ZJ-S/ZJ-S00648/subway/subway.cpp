#include<bits/stdc++.h>
using namespace std;
int w[500005],k[505],a[505][50005],t[505][50005];
int biao[500005];
long long minn=8e18;
int c,n,m,d,q;
void f(int wei,long long sum,int zhong)
{
	biao[wei]=1;
	if(wei==zhong)
	{
		minn=min(minn,sum);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		int flag=0;
		for(int j=1;j<=k[i];j++)
		{
			if(a[i][j]==wei)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			for(int j=1;j<=k[i];j++)
			{
				if(biao[a[i][j]]!=1)
				{
					biao[a[i][j]]=1;
					f(a[i][j],sum+t[i][wei]+t[i][a[i][j]],zhong);
					biao[a[i][j]]=0;
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
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
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
		}
	}
	for(int i=1;i<=q;i++)
	{
		memset(biao,0,sizeof(biao));
		int x,y;
		cin>>x>>y;
		f(x,0ll,y);
		cout<<minn+w[x]+w[y]<<endl;
		minn=8e18;
	}
	return 0;
}
