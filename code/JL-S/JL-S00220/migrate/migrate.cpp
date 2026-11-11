#include <bits/stdc++.h>
#define N 2000005
#define int long long
using namespace std;
set <int> s;
int mn[N],num[N],dis[N],a[N];
queue <int> q;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			s.insert(0);
			mn[i]=0;
			dis[i]=1;
			num[0]++;
			q.push(i);
			for(int j=i+1;j<=n;j++)
			{
				while(!q.empty() && a[q.front()]<a[j]-d)
				{
					int u=q.front();
					q.pop();
					num[mn[u]]-=dis[u];
					if(num[mn[u]]==0)
						s.erase(mn[u]);
				}
				if(q.empty())
					break;
				mn[j]=*s.begin()+1;
				dis[j]=num[mn[j]-1];
				s.insert(mn[j]);
				num[mn[j]]+=dis[j];
				q.push(j);
				ans+=(dis[j]==2);
			}
			/*for(int j=i;j<=n;j++)
			{
				cout<<i<<" "<<j<<" "<<mn[j]<<" "<<dis[j]<<"\n";
			}*/
			while(!q.empty())
				q.pop();
			for(int j=i;j<=n;j++)
				num[mn[j]]=0,mn[j]=dis[j]=0;
			s.clear();
		}
		cout<<ans<<"\n";
	}
}