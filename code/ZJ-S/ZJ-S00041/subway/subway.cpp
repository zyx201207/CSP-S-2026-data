#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=510;
#define int long long
const int inf=1e18+10;
int w[N];
vector<pair<int,int> > v[N];
int dis[M][M];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,m,n,d,q;
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=m;i++)
	{
		int len;
		cin>>len;
		for(int j=1;j<=len;j++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==j) continue;
			dis[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			for(int k=j+1;k<v[i].size();k++)
			{
				int pos1=v[i][j].first,pos2=v[i][k].first;
				//cout<<"*"<<' '<<pos1<<' '<<pos2<<'\n';
				int w=v[i][j].second+v[i][k].second;
				dis[pos1][pos2]=min(dis[pos1][pos2],w);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dis[i][j]=min(dis[i][j],dis[j][i]);
			//cout<<dis[i][j]<<' ';
		}
		//cout<<'\n';
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int minn=inf;
		int x,y;
		cin>>x>>y;
		for(pair<int,int> i:v[x])
		{
			for(pair<int,int> j:v[y])
			{
				minn=min(minn,dis[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<minn+w[x]+w[y]<<'\n';
	}
	return 0;
}

