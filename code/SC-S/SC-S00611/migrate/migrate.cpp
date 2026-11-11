#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,INF=1e18;
int sum[N],num[N],c,t,n,d,x[N],ans,last;
bool vis[N];
queue<int>q;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			q.push(i);sum[i]=0;num[i]=1;
			while(!q.empty())
			{
				int j=q.front();q.pop();vis[j]=0;
				last=j;
				while(j<n&&x[j+1]-x[last]<=d)
				{
					if(!vis[j+1])
					{
						sum[j+1]=sum[last]+1;num[j+1]=num[last];
						q.push(j+1);vis[j+1]=1;
					}
					else if(sum[j+1]==sum[last]+1)
						num[j+1]+=num[last];
					j++;
				}
			}
			for(int j=i+1;j<=n;j++)
				if(num[j]==2)
					ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}