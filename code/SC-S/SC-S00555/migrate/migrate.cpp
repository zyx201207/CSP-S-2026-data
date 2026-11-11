#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <cmath> 
using namespace std;
int c,n,d,t;
int a[2000005];
int cnt[20006][20006];
bool vis[200006];
void bfs(int x,int step)
{
	queue<pair<int,int> > q;
	q.push({x,step});
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop(); 
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&abs(a[x]-a[i])<=d)
			{
				q.push({a[i],step+1});
				cnt[x][i]++;
				vis[i]=1;
			}
		}
	}
}


int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(vis,false,sizeof(vis));
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int p=a[2]-a[1];
		bool flag=true;
		for(int i=3;i<=n;i++)
		{
			if(a[i]-a[i-1]!=p)
			{
				flag=false;
			}
		}
		if(flag)
		{
			int x=a[2]-a[1];
			if(d<2*x||d>3*x||n<4)
			{
				cout<<0<<endl; 
			}
			else
			{
				cout<<n-3<<endl;
			}
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			memset(vis,false,sizeof(vis));
			vis[i]=1;
			bfs(i,0);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(cnt[i][j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}