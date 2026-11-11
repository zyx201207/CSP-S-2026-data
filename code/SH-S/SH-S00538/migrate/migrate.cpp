#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int n;
long long d;
long long a[2000005];
int f[5005][5005];
int cnt[5005][5005];
int dis[5005][5005];
queue<int>q;
void bfs(int s)
{
	memset(cnt,0,sizeof cnt);
	memset(dis,0x3f,sizeof dis);
	dis[s][s]=0;
	q.push(s);
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		for (int i=1;i<=n;i++)
		{
			if (!f[x][i]) continue;
//			cout<<x<<' '<<i<<endl;
			if (dis[s][i]<dis[s][x]+1) continue;
			if (dis[s][i]==dis[s][x]+1)
			{
				cnt[s][i]+=cnt[s][x];
				continue;
			}
			else
			{
				dis[s][i]=dis[x][i]+1;
				cnt[s][i]=1;
				q.push(i);
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int c,t;
	cin>>c>>t;
	while (t--)
	{
		cin>>n>>d;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=i;j<=n;j++)
			{
				if (a[j]-a[i]>d)
				{
					break;
				}
				else
				{
					f[i][j]=1; 
				}
			}
		}
//		for (int i=1;i<=n;i++)
//		{
//			for (int j=1;j<=n;j++)
//			{
//				cout<<f[i][j]<<' ';
//			}
//			cout<<endl;
//		}
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			bfs(i);
			for (int j=1;j<=n;j++)
			{
//				cout<<cnt[i][j]<<' ';
				if (cnt[i][j]==2) ans++;
			}
		}
		cout<<ans<<endl;
//	cout<<0<<endl;
	}
	return 0;
}
