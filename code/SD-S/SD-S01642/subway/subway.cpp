#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int INF=1e4;
const int N=505;
const int K=1e5+5;

int c,n,m,d,q;

int w[K],k[N];
int a[N][K],t[N][K];

int di[N],vis[N];
vector<pair<int,int>> e[N];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=2;j<=k[i];j++)
		{
			int u=a[i][j-1];
			int v=a[i][j];
			int w=t[i][j];
			e[u].push_back({v,w});
			e[v].push_back({u,w});
		}
	}
	
	while(q--)
	{
		int s,en;
		cin>>s>>en;
		int ans=0;
		priority_queue<int,vector<int>,greater<int> > q;
		q.push(s);
		for(int i=1;i<=m;i++)
		{
			di[i]=INF;
			vis[i]=0;
		}
		di[s]=0;
		while(!q.empty())
		{
			int u=q.top();
			q.pop();
			if(vis[u]==1)
			{
				continue;
			}
			vis[u]=1;
			for(int i=0;i<(int)e[u].size();i++)
			{
				int v=e[u][i].first;
				int w=e[u][i].second;
				if(di[v]>di[u]+w)
				{
					di[v]=di[u]+w;
					q.push(v);
				}
			}
		}
		ans+=t[s][s]+w[s]+w[en]+di[en];
		cout<<ans<<"\n";
	}
	return 0;
}
