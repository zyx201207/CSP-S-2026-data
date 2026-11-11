//- Desultory Signals -
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
const int inf=1e18;
int c,n,m,d,q;
int w[N];
vector<int>mp[N];
int ans;
struct node
{
	int k;
	vector<int>a;
	vector<int>t;
}li[N];
pair<int,int> st[N][30];
int top[N];
//int q;
int dis[520][520];
//map<pair<int,int>,int>qwq;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		li[i].k=k;
		for(int j=1;j<=k;j++)
		{
			int a;
			int t;
			cin>>a>>t;
			st[a][++top[a]]={i,t};
			li[i].a.push_back(a);
			li[i].t.push_back(t);
//			qwq[{a,i}]=t;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=top[i];j++)
		{
			for(int k=1;k<=top[i];k++)
			{
				if(j!=k)
				{
					dis[st[i][j].first][st[i][k].first]=min(dis[st[i][j].first][st[i][k].first],st[i][j].second+st[i][k].second);
				}
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<"\n";
//	}
//	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ans=inf;
		for(int i=1;i<=top[x];i++)
		{
			for(int j=1;j<=top[y];j++)
			{
				ans=min(ans,w[x]+w[y]+dis[st[x][i].first][st[y][j].first]+st[x][i].second+st[y][j].second);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//freopen("subway.in","w",stdin);
//freopen("subway.out","r",stdout);
//648647291436