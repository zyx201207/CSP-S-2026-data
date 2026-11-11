#include<bits/stdc++.h>
using namespace std;
int c,T,n,dis[2000005];
long long d,a[2000005],cnt[2000005];
bool b[2000005];
vector<int>g[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			g[i].clear();
			for(int j=1;j<i;j++)if(a[i]-a[j]<=d)g[j].push_back(i);
		}
		for(int i=1;i<=n;i++)
		{
			memset(dis,0x3f,sizeof(dis));
			memset(cnt,0,sizeof(cnt));
			memset(b,0,sizeof(b)); 
			dis[i]=0,cnt[i]=1;
			queue<int>q;
			q.push(i);
			while(!q.empty())
			{
				int u=q.front();
				b[u]=true;
				q.pop();
				for(int v:g[u])
				{
					if(b[v])continue;
					if(dis[v]>dis[u]+1)
					{
						dis[v]=dis[u]+1;
						cnt[v]=cnt[u];
						q.push(v);
					}
					else if(dis[v]==dis[u]+1)
					{
						cnt[v]+=cnt[u];
						if(cnt[v]>=3)cnt[v]=3;
					}
				}
			}
			for(int j=i;j<=n;j++)if(cnt[j]==2)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
