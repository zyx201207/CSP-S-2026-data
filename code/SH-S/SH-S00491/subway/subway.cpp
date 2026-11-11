#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long dist[501][501];
vector<int> w,t[501];
vector<int> a[501];
map<int,vector<int>> mp;
vector<pair<int,long long>> g[501];
map<int,map<int,int>> ids;
void djs(int s)
{
	for(int i=1;i<=n;i++)
	{
		dist[s][i]=0x3f3f3f3f3f3f3f3f;
	}
	priority_queue<pair<long long,int>> pq;
	pq.push({0,s});
	dist[s][s]=0;
	while(!pq.empty())
	{
		pair<long long,int> pp=pq.top();
		pq.pop();
		int u=pp.second;
		if(-pp.first!=dist[s][u])	continue;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].first;
			long long tp=g[u][i].second;
			if(dist[s][v]>dist[s][u]+tp)
			{
				dist[s][v]=dist[s][u]+tp;
				pq.push({-dist[s][v],v});
			}
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	w.resize(m+1);
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		a[i].resize(k+1),t[i].resize(k+1);
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
			mp[a[i][j]].push_back(i);
			ids[a[i][j]][i]=j;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<mp[i].size();j++)
		{
			for(int r=0;r<mp[i].size();r++)
			{
				if(mp[i][j]!=mp[i][r])
				{
					int tmp=t[mp[i][j]][ids[i][mp[i][j]]]+t[mp[i][r]][ids[i][mp[i][r]]];
					g[mp[i][j]].push_back({mp[i][r],tmp});
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		djs(i); 
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		long long ans=w[x]+w[y],tmp=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<mp[x].size();i++)
		{
			for(int j=0;j<mp[y].size();j++)
			{
				tmp=min(tmp,dist[mp[x][i]][mp[y][j]]+t[mp[x][i]][ids[x][mp[x][i]]]+t[mp[y][j]][ids[y][mp[y][j]]]);
			}
		}
		cout<<ans+tmp<<'\n';
	}
	return 0;
}
