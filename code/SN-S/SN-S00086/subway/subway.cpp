#include<iostream>
#include<vector>
#include<queue>
#define int long long
using namespace std;
int c,n,m,d,q1;
int w[500005];
int k[505];
vector<int> a[505],t[505];
vector<pair<int,int> > v[1100000];//new len
queue<pair<int,pair<int,int> > > q;//f new len
int bfs(int x,int y)
{
	if(!q.empty()) q.pop();
	q.push({x,{x,0}});
	while(!q.empty())
	{
		int s=q.front().second.first;
		int f=q.front().first;
		int len=q.front().second.second;
//		cout<<s<<" "<<f<<" "<<len<<"\n";
		if(s==y) return len;
		q.pop();
		for(int i=0;i<v[s].size();i++)
		{
//			cout<<len+v[s][i].second<<"\n";
			if(v[s][i].first!=f) q.push({s,{v[s][i].first,len+v[s][i].second}});
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		v[i].push_back({i+m,w[i]});
		v[i+m].push_back({i,w[i]});
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int a1,t1;
			cin>>a1>>t1;
			v[a1+m].push_back({m*2+i,t1});
			v[m*2+i].push_back({a1+m,t1});
			a[i].push_back(a1);
			t[i].push_back(t1);
		}
	}
	for(int i=1;i<=q1;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<bfs(x,y)<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
