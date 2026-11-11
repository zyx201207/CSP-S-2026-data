#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,a[N],num[N],tim[N],minn=2147483647,u[1005][1005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,t;
			cin>>x>>t;
			u[i][x]=t;
			tim[x]+=t;
			if(num[x]>0||num[x]==-1)
			{
				num[x]=-1;
			}
			else
			{
				num[x]=i;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(num[i]==-1)
		{
			minn=min(minn,tim[i]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y,ans=0;
		cin>>x>>y;
		ans+=a[x]+a[y]+tim[x]+tim[y];
		if(num[x]!=num[y])
		{
			ans+=minn;
		}
		if(num[x]==-1)
		{
			ans=ans-minn-tim[x];
			ans+=u[num[y]][x];
		}
		if(num[y]==-1)
		{
			ans=ans-minn-tim[y];
			ans+=u[num[x]][y];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
