#include<iostream>
using namespace std;
int x[105];
int minn=1e9;
int sum=0;
void dfs1(int pos,int v,int d,int cnt)
{
	if(pos==v)
	{
		minn=min(minn,cnt);
		return ;
	}
	for(int i=pos+1;i<=v;i++)
	{
		if(x[i]-x[pos]>d)
		{
			break;
		}
		dfs1(i,v,d,cnt+1);
	}
}
void dfs2(int pos,int v,int d,int cnt)
{
	if(pos==v)
	{
		if(cnt==minn)
		{
			sum++;
		}
		return ;
	}
		for(int i=pos+1;i<=v;i++)
	{
		if(x[i]-x[pos]>d)
		{
			break;
		}
		dfs2(i,v,d,cnt+1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	
	while(t--)
	{
		int ans=0;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int u=1;u<=n;u++)
		{
			for(int v=u;v<=n;v++)
			{
				minn=1e9,sum=0;
				dfs1(u,v,d,0);
				dfs2(u,v,d,0);
				if(sum==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
