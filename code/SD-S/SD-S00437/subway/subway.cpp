#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500+10;
int a[N][N],t[N][N],w[N],dis[N],vis[N];
vector<pair<int,int> > vec[N];
void solve_problems()
{
	int x,y;
	cin>>x>>y;
	queue<int> que;
	que.push(x);
	memset(dis,-1,sizeof(dis));
	dis[x]=0;
	while(que.size()!=0)
	{
		int now=que.front();
		vis[now]=true;
		que.pop();
		int len=vec[now].size();
		for(int v=0;v<len;v++)
		{
			if(vis[vec[now][v].first]==false)
			{
				que.push(vec[now][v].first);
				vis[vec[now][v].first]=true;
			}
			if(dis[now]>dis[v]+vec[now][v].second)
			{
				dis[now]=dis[v]+vec[now][v].second;
			}
		}
	}
	cout<<dis[y]<<"\n";
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,Q;
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		vec[i].push_back(make_pair(m+1,w[i]));
		vec[m+1].push_back(make_pair(i,w[i]));
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
			if(j!=1)
			{
				vec[a[i][j-1]].push_back(make_pair(a[i][j],0));
				vec[a[i][j]].push_back(make_pair(m+1,t[i][j]));
				vec[m+1].push_back(make_pair(a[i][j],t[i][j]));
			}
		}
	}
	for(int q=1;q<=Q;q++)
	{
		solve_problems();
	}
	return 0;
}
