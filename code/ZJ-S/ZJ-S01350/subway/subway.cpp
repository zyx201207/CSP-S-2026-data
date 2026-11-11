#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5,inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[M];
vector<pair<int,int>>gr[M+N];
int dis[M+N];
int ds[N][N];
bool vis[M+N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
void dij(int st)
{
	int sum=n;
	for(int i=1;i<=n+m;i++)dis[i]=inf,vis[i]=0;
	dis[st]=0;
	while(!pq.empty())pq.pop();
	pq.push({0,st});
	while(!pq.empty())
	{
		int dt=pq.top().second,w=pq.top().first;
		pq.pop();
		if(vis[dt])continue;
		vis[dt]=1;
		if(dt>m)sum--;
		for(pair<int,int>i:gr[dt])
		{
			if(i.first+w<dis[i.second])
			{
				dis[i.second]=i.first+w;
				pq.push({dis[i.second],i.second});
			}
		}	
		if(sum==0)break;
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			gr[a].push_back({t,i+m});
			gr[i+m].push_back({t,a});
		}
	}
	for(int i=1;i<=n;i++)
	{
		dij(m+i);
		for(int j=m+1;j<=m+i;j++)
		{
			ds[i][j-m]=dis[j];
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int mi=inf;
		for(pair<int,int>i:gr[x])
		{
			for(pair<int,int>j:gr[y])
			{
				int s=i.second,e=j.second;
				if(s<e)swap(s,e);
				mi=min(mi,ds[s-m][e-m]+i.first+j.first);
			}
		}
		cout<<mi+w[x]+w[y]<<'\n';
	}
	return 0;
}