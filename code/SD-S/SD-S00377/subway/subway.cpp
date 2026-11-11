#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
const int N=5e2+5,K=5e5+5,M=1e6+5,inf=0x3f3f3f3f3f3f3f3f,eps=1e-8;
int w[M],k[M],dis[M],vis[M];
vector<pair<int,int> > e[N];
int idx=0,allnode;
int dj(int s,int t)
{
	for(int i=1;i<=allnode;i++) dis[i]=inf;
	for(int i=1;i<=allnode;i++) vis[i]=0;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({0,s});dis[s]=0;
	while(!q.empty())
	{
		int u=q.top().second,len=q.top().first;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto it:e[u])
		{
			int v=it.first,l=it.second;
			if(dis[u]+l<dis[v])
			{
				dis[v]=dis[u]+l;
				q.push({dis[v],v}); 
			}
		}
	}
	return dis[t];
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr); 
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	allnode=n+m;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int aij,tij;cin>>aij>>tij;
			e[aij].push_back({i+m,tij});
			e[i+m].push_back({aij,tij});
		}
	}
	while(q--)
	{
		int x,y;cin>>x>>y;
		cout<<dj(x,y)+w[x]+w[y]<<'\n';
	}
	return 0;
}

