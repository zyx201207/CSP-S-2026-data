#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+50;
int c,n,m,d,q;
int w[N];
vector<pair<int,int>> e[N*3];
int dis[505][N*3];
void Dij(int s,int i)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	dis[i][s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int u=q.top().second;
		int d=q.top().first;
		q.pop();
		if(d!=dis[i][u])continue;
//		if(i==2)cout<<u<<' ';
		for(pair<int,int> to:e[u])
		{
			int v=to.first,w=to.second;
//			if(i==1)cout<<v<<":"<<w<<" ";
			if(dis[i][v]>dis[i][u]+w)
			{
				dis[i][v]=dis[i][u]+w;
				q.push(make_pair(dis[i][v],v));
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		vector<int> s;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			e[(i-1)*m+a].push_back(make_pair(n*m+a,t));
			e[n*m+a].push_back(make_pair((i-1)*m+a,t));
			s.push_back(a);
		}
		for(int x=0;x<k;x++)
		{
			for(int y=x+1;y<k;y++)
			{
				int u=(i-1)*m+s[x];
				int v=(i-1)*m+s[y];
				e[u].push_back(make_pair(v,0));
				e[v].push_back(make_pair(u,0));
			}
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++)
	{
		Dij(i+n*m,i);
//		cout<<e[i+n*m].size()<<" ";
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<dis[r][n*m+l]+w[l]+w[r]<<"\n";
	}
	return 0;
}

