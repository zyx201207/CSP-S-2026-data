#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int w[500005],k[505];
struct node
{
	long long a,t;
}x[505][50005];
long long minn=1000000005;
int visited[505][50005];
void dfs(int xx,int yy,long long cnt)
{
	if(xx==yy){minn=min(minn,cnt);cout<<minn<<11111<<endl;return;}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			if(x[i][j].a==xx && visited[i][j]==0)
			{
				
				for(int jj=1;jj<=k[i];jj++)
				{
					if(j==jj)
					{
						visited[i][jj]=1;
						dfs(x[i][jj].a,yy,cnt+x[i][jj].t);
						visited[i][jj]=0;
					}
					else
					{
						visited[i][j]=1;
						visited[i][jj]=1;
						dfs(x[i][jj].a,yy,cnt+x[i][jj].t+x[i][j].t);
						visited[i][j]=0;
						visited[i][jj]=0;
					}
					
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
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>x[i][j].a>>x[i][j].t;
		}
	}
	while(q--)
	{
		int xx,yy;
		cin>>xx>>yy;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k[i];j++)
			{
				if(x[i][j].a==xx){
				for(int jj=1;jj<=k[i];jj++)
				{
					if(j==jj)
					{
						visited[i][jj]=1;
						dfs(x[i][jj].a,yy,w[xx]+w[yy]+x[i][jj].t);
						visited[i][jj]=0;
					}
					else
					{
						visited[i][j]=1;
						visited[i][jj]=1;
						dfs(x[i][jj].a,yy,w[xx]+w[yy]+x[i][jj].t+x[i][j].t);
						visited[i][j]=0;
						visited[i][jj]=0;
					}
					
				}}
			}
		}
		
		cout<<minn<<endl;
		minn=1000000005;
		for(int i=1;i<=501;i++)
		{
			for(int j=1;j<=50001;j++)visited[i][j]=0;
		}
	}
	
    return 0;
}
