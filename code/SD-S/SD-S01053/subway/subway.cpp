#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAXX 4557430888798830399
int o,n,m,d,q;
int w[500005];
int dis[500005];

struct Edge
{
	int to,k;
};
vector <Edge>edge[505];
int lin[505][505];
struct stst
{
	int to,k;
};
vector<stst> sas[500005];
struct lu
{
	int to,k;
	bool operator >(const lu &other)const
	{
		k>other.k;
	}
};

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>o>>n>>m>>d>>q;
	memset(sas,0,sizeof(sas));
	memset(lin,MAXX,sizeof(lin));
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
    }
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int a,s;
			cin>>a>>s;
			sas[a].push_back({i,s});
		}
	}
	for(int p=1;p<=m;p++)
	{
		for(int i=0;i<sas[p].size();i++)
		{
			for(int j=0;j<sas[p].size();j++)
			{
				if(i!=j)
				{
					lin[sas[p][i].to][sas[p][j].to]=min(lin[sas[p][i].to][sas[p][j].to],sas[p][i].k+sas[p][j].k);
					lin[sas[p][j].to][sas[p][i].to]=lin[sas[p][i].to][sas[p][j].to];
				}
			}
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(lin[i][j]!=MAXX)
			{
				edge[i].push_back({j,lin[i][j]});
			}
		}
	}
	while(q--)
	{
		priority_queue<lu ,vector<lu>,greater<lu> >dui;
		for(int i=0;i<=n+1;i++)dis[i]=MAXX;
		int x,y;
		cin>>x>>y;
		edge[0].clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=edge[i].size()-1;j>=0;j--)
			{
				if(edge[i][j].to==n+1)
				{
					edge[i].erase(edge[i].begin()+j);
				}
				break;
			}
		}
		for(int i=0;i<sas[x].size();i++)
		{
			edge[0].push_back({sas[x][i].to,sas[x][i].k}) ;
		}
		for(int i=0;i<sas[y].size();i++)
		{
			edge[sas[y][i].to].push_back({n+1,sas[y][i].k}) ;
		}
		dui.push({0,0});
		dis[0]=0;
		while(!dui.empty())
		{
			lu now=dui.top();
			dui.pop();
			if(now.k>dis[now.to])continue;
			dis[now.to]=now.k;
			for(int i=0;i<edge[now.to].size();i++)
			{
				if(dis[now.to]+edge[now.to][i].k<=dis[edge[now.to][i].to])
				{
					dis[edge[now.to][i].to]=dis[now.to]+edge[now.to][i].k;
					dui.push({edge[now.to][i].to,dis[edge[now.to][i].to]});
				}
			}
		}
		cout<<dis[n+1]+w[x]+w[y]<<endl;
		
	}
	return 0;
 } 
