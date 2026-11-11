#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],dist[500005];
vector<pair<int,int> >e[505];
vector<pair<int,int> > a[500005];
struct node
{
	int now,way,out;
};
void bfs(int st,int ed)
{
	memset(dist,0x3f,sizeof dist);
	queue<node > q;
	q.push({st,-1,0});
	dist[st]=0;
	int ans=0x3f3f3f3f;
	while(q.size())
	{
		auto [u,way,out]=q.front();q.pop();
		if(u==ed)
		{
			ans=min(ans,dist[ed]+w[st]+w[ed]+out);
			continue;
		}
		for(auto [k,o]:a[u])
		{
			for(auto [v,cost]:e[k])
			{
				if(v==u)continue;
				if(k==way)
				{
					if(dist[u]<dist[v])
					{
						dist[v]=dist[u];
						q.push({v,way,cost});
					}
				}
				else
				{
					if(dist[u]+out+o<dist[v])
					{
						dist[v]=dist[u]+out+o;
						q.push({v,k,cost});
					}
				}
			}
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		cin>>x;
		while(x--)
		{
			cin>>y>>z;
			a[y].push_back({i,z});
			e[i].push_back({y,z});
		}
	}
	while(q--)
	{
		int st,ed;
		cin>>st>>ed;
		bfs(st,ed);
	}
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/