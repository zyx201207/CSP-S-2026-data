#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pir;
long long c,n,m,d,q;
long long k[505];
long long w[500005];
long long dis[505][505];
bool st[505];
vector<pir> s[500005];
vector<pir> g[505];
priority_queue<pir,vector<pir>,greater<pir> > que;
void dijkstra(long long p)
{
	for(long long i=1;i<=n;i++) dis[p][i]=1e18,st[i]=false; 
	que.push({0,p});
	dis[p][p]=0;
	while(!que.empty())
	{
		pir t=que.top();
		que.pop();
		if(st[t.second]) continue;
		st[t.second]=true;
		for(auto it:g[t.second])
		{
			if(dis[p][it.first]>dis[p][t.second]+it.second)
			{
				dis[p][it.first]=dis[p][t.second]+it.second;
				que.push({dis[p][it.first],it.first});
			}
		}
	} 
}
void solve()
{
	for(long long i=1;i<=n;i++)
	{
		cin>>k[i];
		long long cur=0,t;
		for(long long j=1;j<=k[i];j++)
		{
			cin>>cur>>t;
			s[cur].push_back({i,t});
		}
	}
	for(long long i=1;i<=m;i++)
	{
		if(s[i].size()>1)
		  for(long long j=0;j<s[i].size();j++)
		    for(long long l=j+1;l<s[i].size();l++)
		    {
		    	g[s[i][j].first].push_back({s[i][l].first,s[i][j].second+s[i][l].second});
		    	g[s[i][l].first].push_back({s[i][j].first,s[i][j].second+s[i][l].second});
			}
	}
	/*for(long long i=1;i<=15;i++,cout<<endl)
	{
		cout<<i<<' ';
		for(auto it:g[i]) cout<<it.first<<" "<<it.second<<"   ";
	}*/
	for(long long i=1;i<=n;i++)
	  dijkstra(i);
	while(q--)
	{
		long long x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(auto it:s[x])
		{
			for(auto item:s[y])
			{
			//	cout<<y+(item.first-1)*m<<" "<<dis[y+(item.first-1)*m]<<" "<<it.second<<" "<<item.second<<" "<<w[x]<<" "<<w[y]<<endl;
				ans=min(ans,dis[it.first][item.first]+it.second+item.second+w[y]+w[x]);
			}
		}
		cout<<ans<<'\n';
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) 
	  cin>>w[i];
	solve(); 
	return 0;
}
