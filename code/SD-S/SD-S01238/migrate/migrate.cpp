#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5010;
int a[N],f[N][N],g[N][N];
vector<int> edges[N];
queue<pair<int,int> > q;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int C,t;
	cin>>C>>t;
	while(t--)
	{
		int n,ans=0,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d) edges[i].push_back(j);
				else break;
			}
		for(int i=1;i<=n;i++)
		{
			while(q.size()) q.pop();
			q.push({i,1});
			f[i][i]=1;
			while(!q.empty())
			{
				pair<int,int> t=q.front();
				q.pop();
				int u=t.first,step=t.second;
				for(int v:edges[u])
				{
					if(f[i][v])
					{
						if(step==g[i][v]) f[i][v]++;
						continue;
					}
					g[i][v]=step;
					f[i][v]=1;
					q.push({v,step+1});
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(i<j&&f[i][j]==2) ans++;
				f[i][j]=0;
			}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++) g[i][j]=0;
		for(int i=1;i<=n;i++) edges[i].clear();
		cout<<ans<<"\n";
	}
	return 0;
}
