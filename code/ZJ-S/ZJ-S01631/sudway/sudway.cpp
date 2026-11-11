#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k;
long long w[500005],a[50005][505],t[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("sudway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=50005;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[0][i];
		long long maxx=-1;
		for(int j=1;j<=a[0][i];j++)
		{
			long long lu,time;
			cin>>lu>>time;
			maxx=max(maxx,lu);
			a[lu][i]=time;
		}
		a[0][i]=maxx;
	}
	while(q--)
	{
		bool f=1;
		long long oo=1,ok,x,y,ans=0,minn=INT_MAX;
		cin>>x>>y;
		ans+=w[x]+w[y];
		for(int i=x;i<=y;i++)
		{
			minn=INT_MAX;
			if(i==x+1)
			{
				f=0;
				oo=ok;
			}
			for(int j=1;j<=n;j++)
			{
				if(minn>a[i][j])
				{
					minn=a[i][j];
					ok=j;
				}
			}
			if(ok!=oo&&f==0&&y!=i)
			{
				ans+=a[i][ok]+a[i][oo];
				oo=ok;
			}
			else if(y==i)
			{
				ans+=a[i][oo];
			}
			else ans+=minn;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
