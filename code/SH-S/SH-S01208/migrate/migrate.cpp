#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int c,t,ans=0;
long long x[305];
int cnt[305][305];
int dis[305][305]; 
queue<int>q;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		ans=0;
		for(int i=1;i<=300;i++)
		{
			for(int j=1;j<=300;j++)
			{
				cnt[i][j]=0;
				dis[i][j]=2e9;
			}
		}
		long long n,d;
		memset(x+1,0,sizeof(x));
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(c<=6)
		{
			
			while(!q.empty())
			{
				int now=q.front();
				q.pop();
				for(int i=1;i<=n;i++)
				{
					int dst=x[now]-x[i];
					if(dst<=0)dst*=-1;
					for(int j=1;j<=n;j++)
					{
						if(dis[i][now]>dis[i][j]+dst)
						{
							dis[i][now]=dis[i][j]+dst;
							dis[now][i]=dis[i][now];
							cnt[i][j]=0;
							cnt[j][i]=0;	
							q.push(i);
						}
						if(dis[i][now]==dis[i][j]+dst)
						{
							cnt[i][j]++;
							cnt[j][i]++;	
							q.push(i);
						}
					}
					
				}
			}
			for(int i=1;i<n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(cnt[i][j]==2)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}	
	return 0;
}
