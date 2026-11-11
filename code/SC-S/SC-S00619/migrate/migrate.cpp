#include<bits/stdc++.h>
using namespace std;
int n,d,c,t,x[2000005],ans,cnt,minn;
void dfs(int u,int v,int sum)
{
	if(u==v)
	{
		if(minn==sum)cnt++;
		else if(minn>sum)minn=sum,cnt=1;
		return ;
	}
	for(int i=u+1;i<=v&&x[i]-x[u]<=d;i++)
	{
		dfs(i,v,sum+1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				minn=0x3f3f3f3f;
				cnt=0;
				dfs(i,j,0);
				if(cnt==2)
				{
					ans++;
				}
				if(cnt>2)break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
 0 2
 5 3
-2 -1 0 1 2
 6 2
-4 -3 -2 -1 3 6
*/