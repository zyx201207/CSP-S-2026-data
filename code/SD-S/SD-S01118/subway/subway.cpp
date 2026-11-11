#include<bits/stdc++.h>
using namespace std;
const long long N=5e2+5,M=5e5+5;
long long C,n,m,w,que,ans;
long long a[M],f[M][21],vis[N];
struct node
{
	long long v,t;
};
struct NODE
{
	long long x,sum,id;
};
vector<node> s[N],d[M];
queue<NODE> q;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>w>>que;
	for(long long i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++)
		{
			long long v,t;
			cin>>v>>t;
			s[i].push_back(node{v,t});
			d[v].push_back(node{i,t});
		}
	}
	while(que--)
	{
		ans=1e18;
		memset(f,0x3f,sizeof(f));memset(vis,0,sizeof(vis));
		while(!q.empty())q.pop();
		long long x,y;
		cin>>x>>y;
		for(long long i=0;i<d[x].size();i++)
		{
			q.push(NODE{x,d[x][i].t,d[x][i].v});
			f[x][d[x][i].v]=d[x][i].t;
		}
		while(!q.empty())
		{
			long long x=q.front().x,sum=q.front().sum,t=q.front().id;;
			q.pop();
			vis[t]=1;
			long long p=0;
			for(long long i=0;i<s[t].size();i++)
			{
				long long v=s[t][i].v,w=s[t][i].t;
				if(v==x)continue;
				if(v==y)
				{
					ans=min(ans,sum+w);
					continue;
				}
				for(long long j=0;j<d[v].size();j++)
				{
					long long o=d[v][j].v;
					if(t==o)continue;
					if(vis[o])continue;
					if(f[v][o]<=sum+w+d[v][j].t)continue;
					f[v][o]=sum+w+d[v][j].t;
					q.push(NODE{v,sum+w+d[v][j].t,o});
				}
			}
		}
		cout<<ans+a[x]+a[y]<<"\n";
	}
	return 0;
}

