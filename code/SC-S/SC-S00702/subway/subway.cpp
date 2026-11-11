#include<bits/stdc++.h>
using ll=long long;
using namespace std;
ll c,n,m,d,Q;
ll w[500505];
vector<pair<ll,ll>>g[600505];
ll dist[2010][2010];
struct no{
	ll u,w;
};
bool operator < (const no &a,const no &b)
{
	return a.w>b.w;
}
priority_queue<no>q;
bool vs[2002];
void dij(ll x)
{
	for(int i=1;i<=n+m;i++)vs[i]=0;
	q.push({x,0});
	dist[x][x]=0;
	while(q.size())
	{
		ll u=q.top().u,s=q.top().w;
		q.pop();
		if(vs[u])continue;
		vs[u]=1;
		for(auto V:g[u])
		{
			ll v=V.first,w=V.second;
			if(dist[x][v]>dist[x][u]+w)
			{
				dist[x][v]=dist[x][u]+w;
				q.push({v,dist[x][v]});
			}
		}
	}
	return ;
}
pair<ll,ll>dii[500505];
queue<ll>pp;
ll bfs(ll x,ll y)
{
	if(dii[1].second==x)return dii[y].first;
	dii[x]={0,x};
	while(pp.size())pp.pop();
	pp.push(x);
	while(pp.size())
	{
		ll u=pp.front();
		pp.pop();
		for(auto V:g[u])
		{
			ll v=V.first,w=V.second;
			if(dii[v].second!=x)
			{
				dii[v].second=x;
				dii[v].first=dii[u].first+w;
				if(v==y)
				{
					return dii[v].first;
				}
				pp.push(v);
			}
		}
	}
	return 0;
}
ll mai=1e18;
ll get(ll x,ll y)
{
	if(g[x].size()==1&&g[y].size()==1)
	{
		if(g[x][0].first==g[y][0].first)
		{
			return g[y][0].second+g[x][0].second;
		}
		else
		{
			return g[y][0].second+g[x][0].second+mai;
		}
	}
	else if(g[x].size()==1&&g[y].size()==2)
	{
		if(g[y][0].first==g[x][0].first)
		{
			return g[x][0].second+min(g[y][0].second,mai+g[y][1].second);
		}
		else
		{
			return g[x][0].second+min(g[y][1].second,mai+g[y][0].second);
		}
	}
	else if(g[x].size()==2&&g[y].size()==1)
	{
//		cout<<x<<" "<<y<<"||\n";
		if(g[x][0].first==g[y][0].first)
		{
			return g[y][0].second+min(g[x][0].second,mai+g[x][1].second);
		}
		else
		{
			return g[y][0].second+min(g[x][1].second,mai+g[x][0].second);
		}
	}
	else
	{
		if(g[x][0].first==g[y][0].first)
		{
			return min({g[x][1].second+g[y][1].second,g[x][0].second+g[y][0].second,g[x][0].second+mai+g[y][1].second,g[y][0].second+mai+g[x][1].second});
		}
		else
		{
			return min({g[x][0].second+g[y][1].second,g[x][1].second+g[y][0].second,g[x][1].second+mai+g[y][1].second,g[y][0].second+mai+g[x][0].second});
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			ll x,y;
			cin>>x>>y;
			g[m+i].push_back({x,y});
			g[x].push_back({m+i,y});
			if(g[x].size()==2)
			{
				mai=min(mai,g[x][0].second+g[x][1].second);
			}
		}
	}
	if(c<=11)
	{
		memset(dist,0x3f,sizeof dist);
		for(int i=1;i<=m;i++)dij(i);
	}
	for(int kk=1;kk<=Q;kk++)
	{
		ll l,r;
		cin>>l>>r;
		if(c<=11)
		{
			cout<<dist[l][r]+w[l]+w[r]<<"\n";
		}
		if(12<=c&&c<=15)
		{
			cout<<(bfs(l,r)+w[l]+w[r])<<"\n";
		}
		if(20<=c&&c<=21)
		{
			cout<<(get(l,r)+w[l]+w[r])<<"\n";
		}
	}
	return 0;
}
/*
 0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3   4 5 7
1 3
1 2
*/
/*
  0 3 7 20 2
 8 3 6 1    7 2 9
   3 1 4 2  5 5  100
   3  2 6 3   1 7 2
  4 3 2 5 100 4 6 6 7
  1 6
  2 3
*/

/*
20 2 6 91 5
0 0 0 0 0 0
3 1 5 3 10 5 6
4 1 7 2 3 4 9 5 8 
1 3
1 2
2 3
4 5
3 4

*/