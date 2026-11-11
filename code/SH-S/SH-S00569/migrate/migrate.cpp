#include<bits/stdc++.h>

using namespace std;

int n,d,flag,ans,x,y,a[500005],flag1,mm,tu[500005],maxn;

void dfs(int turn,int now)
{
	if(now==y)
	{
		tu[turn]++;
		maxn=min(maxn,turn);
	}
	for(int i=1;i<=d;i++)
	{
		if(now+i>n)
		{
			break;
		}
		dfs(turn+1,now+i);
	}
	return ;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int _,t;
	cin>>_>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				memset(tu,0,sizeof(tu));
				mm=0;
				maxn=1e9;
				x=i,y=j;
				dfs(0,i);
				if(tu[maxn]>=2)
				{
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
