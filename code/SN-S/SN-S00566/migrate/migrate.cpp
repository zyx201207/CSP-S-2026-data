#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d;
int w[100005];
vector<int> e[100005];
pair<int,int> f[305][305];
struct node
{
	int now;
	int cnt,beg;
};
queue<node> q;
void bfs()
{
	while(!q.empty())
	{
		q.pop();
	}
	for(int i=1;i<=n;i++)
	{
		q.push({i,0,i});
	}
	while(!q.empty())
	{
		auto x=q.front();
		q.pop();
		int u=x.now;
		int cnt=x.cnt;
		int beg=x.beg;
		for(int v:e[u])
		{
			if(f[beg][v].first==0 || f[beg][v].first>cnt+1)
			{
				f[beg][v]={cnt+1,1};
			}
			else if(f[beg][v].first==cnt+1)
			{
				f[beg][v].second++;
			}
			q.push({v,cnt+1,beg});
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>w[i];
		}
		for(int i=1;i<=n;i++)
		{
			e[i].clear();
			for(int j=i+1;j<=n;j++)
			{
				if(abs(w[j]-w[i])<=d)
				{
					e[i].push_back(j);
				}
				else
				{
					break;
				}
			}
		}
		bfs();
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans+=(f[i][j].second==2);
				f[i][j]={0,0};
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

