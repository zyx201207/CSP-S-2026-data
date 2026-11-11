#include<bits/stdc++.h>
using namespace std;
int T,n,m,d,q;
long long w[500005],sd[505][505];
vector<long long> t[505];
bool vis[505][500005],flag[505],isside[505][505];
__int128 dis[500005];
long long M=9e18;
void init()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sd[i][j]=M;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++) t[i].push_back(0);
	}
}
__int128 dij(int st,int ft)
{
	for(int i=1;i<=m;i++) dis[i]=M;
	for(int i=1;i<=n;i++) flag[i]=false;
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > pq;
	pq.push({0,st});
	dis[st]=0;
	flag[st]=true;
	while(!pq.empty())
	{
		pair<long long,int> p=pq.top();
		pq.pop();
		for(int i=1;i<=n;i++)
		{
			if(!isside[p.second][i]||flag[i]) continue;
			if(dis[i]>sd[p.second][i]+p.first)
			{
				dis[i]=sd[p.second][i]+p.first;
				flag[i]=true;
				pq.push({dis[i],i});
				break;
			}
		}
	}
	return dis[ft];
}
void print(long long x)
{
	long long a=x%10;
	if(x>10) print(x/10);
	else a=x;
	cout<<a;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T>>n>>m>>d>>q;
	init();
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			long long a,b;
			cin>>a>>b;
			vis[i][a]=true;
			t[i][a]=b;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int x=1;x<=m;x++)
			{
				if(vis[i][x]&&vis[j][x]) 
				{
					sd[i][j]=min(sd[i][j],t[i][x]+t[j][x]);	
					isside[i][j]=true;
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		__int128 ans=M;
		cin>>x>>y;
		for(int j=1;j<=n;j++)
		{
			for(int jj=1;jj<=n;jj++)
			{
				if(vis[j][x]&&vis[jj][y]) ans=min(ans,(dij(j,jj)+t[j][x]+t[jj][y]));
			}
		}
		print(ans+w[x]+w[y]);
		cout<<"\n";
	}
	return 0;
}