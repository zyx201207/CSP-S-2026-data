#include <bits/stdc++.h>
#define int long long
using namespace std;
/*====================*/
const int N=5e5+50;
const int M=5e2+5;
const int Q=1e5+50;
int w[N];
vector<pair<int,pair<int,int> > > v[2][N];
int dist[2][N];
bool flag[2][N];
pair<int,pair<int,int> > ans[Q];
int cnt[Q];
/*====================*/
void dijkstra(int s)
{
	memset(dist,0x3f,sizeof(dist));
	memset(flag,false,sizeof(flag));
	priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > q;
	dist[1][s]=0;
	q.push({0,{1,s}});
	while(!q.empty())
	{
		auto u=q.top();
		q.pop();
		if(flag[u.second.first][u.second.second]==true)
		{
			continue;
		}
		flag[u.second.first][u.second.second]=true;
		for(auto i:v[u.second.first][u.second.second])
		{
			if(dist[i.second.first][i.second.second]>dist[u.second.first][u.second.second]+i.first)
			{
				dist[i.second.first][i.second.second]=dist[u.second.first][u.second.second]+i.first;
				q.push({dist[i.second.first][i.second.second],{i.second.first,i.second.second}});
			}
		}
	}
}
/*====================*/
void Solve(void)
{
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
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
			int x,y;
			cin>>x>>y;
			v[1][x].push_back({y,{0,i}});
			v[0][i].push_back({y,{1,x}});
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>ans[i].first>>ans[i].second.first;
		ans[i].second.second=i;
	}
	sort(ans+1,ans+q+1);
	for(int i=1;i<=q;i++)
	{
		if(ans[i].first==ans[i-1].first)
		{
			cnt[ans[i].second.second]=dist[1][ans[i].second.first]+w[ans[i].first]+w[ans[i].second.first];
		}
		else
		{
			dijkstra(ans[i].first);
			cnt[ans[i].second.second]=dist[1][ans[i].second.first]+w[ans[i].first]+w[ans[i].second.first];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout<<cnt[i]<<endl; 
	}
}
/*====================*/
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;//cin>>T;
	while(T--) Solve();
	return 0;
}
/*

*/
