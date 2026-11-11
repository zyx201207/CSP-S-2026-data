#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using i64=long long;
const int N=505,M=5e3+5;
int _,n,m,d,q;
int w[M];
vector<pair<int,int>> lines[N];
vector<pair<int,int>> g[M];
priority_queue<pair<i64,int>,vector<pair<i64,int>>,greater<pair<i64,int>>> Q;
i64 dis[M][M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>_>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for (int j=1;j<=k;j++)
		{
			int x,t;
			cin>>x>>t;
			lines[i].push_back({x,t});
		}
		for (int j=0;j<k;j++)
		{
			for (int h=j+1;h<k;h++)
			{
				int id1=lines[i][j].first,t=lines[i][j].second,id2=lines[i][h].first,t2=lines[i][h].second;
				g[id1].push_back({id2,t+t2});
				g[id2].push_back({id1,t+t2});
			}
		}
	}
	for (int i=1;i<=m;i++)
	{
		Q.push({0,i});
		for (int j=1;j<=m;j++)dis[i][j]=1e18;
		dis[i][i]=0;
		while (Q.size())
		{
			auto cur=Q.top();
			auto d=cur.first;
			auto u=cur.second;
			Q.pop();
			if (d!=dis[i][u])	continue;
			for (auto cur:g[u])
			{
				auto v=cur.first,w=cur.second;
				if (dis[i][v]>d+w)
				{
					dis[i][v]=d+w;
					Q.push({dis[i][v],v});
				}
			}
		}
	}
	while (q--)
	{
		int st,ed;
		cin>>st>>ed;
		cout<<dis[st][ed]+w[st]+w[ed]<<"\n";
	}
	return 0;
}

