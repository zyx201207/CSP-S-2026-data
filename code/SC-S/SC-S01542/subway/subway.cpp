#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510,M=5e5+5;
ll dis[N][N];
vector<pair<int,int> > p[M];
int c,n,m,d,q;
int w[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		for(int j=1,x,y;j<=k;j++)
		{
			cin>>x>>y;
			p[x].push_back(make_pair(i,y));
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int t=(int)p[i].size();
		for(int j=0;j<t;j++)
		{
			pair<int,int> tmp=p[i][j];
			for(int k=j+1;k<t;k++)
			{
				pair<int,int> temp=p[i][k];
				ll tp=tmp.second+temp.second;
				dis[tmp.first][temp.first]=min(dis[tmp.first][temp.first],tp);
				dis[temp.first][tmp.first]=min(dis[temp.first][tmp.first],tp);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dis[i][k]+dis[k][j]<dis[i][j])
					dis[i][j]=dis[i][k]+dis[k][j];
	while(q--)
	{
		int x,y;
		ll minn=1e18;
		cin>>x>>y;
		for(int i=0;i<(int)p[x].size();i++)
		{
			pair<int,int> t=p[x][i];
			for(int j=0;j<(int)p[y].size();j++)
			{
				pair<int,int> tp=p[y][j];
				minn=min(minn,dis[t.first][tp.first]+t.second+tp.second);
			}
		}
		minn+=w[x]+w[y];
		cout<<minn<<'\n';
	}
	return 0;
}