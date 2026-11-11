#include<bits/stdc++.h>
using namespace std;
struct node
{
	int to,w;
};
int c,m,n,d,t;
vector<vector<node> > z;
vector<int> ans,cost;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void find(int start)
{
	fill(ans.begin(),ans.end(),0x3fffffff);
	ans[start]=0;
	while (!q.empty())
	{
		q.pop();
	}
	q.push({0,start});
	while (!q.empty())
	{
		int u=q.top().second;
		int d=q.top().first;
		q.pop();
		if (d>ans[u])
		{
			continue;
		}
		for (int i=0;i<z[u].size();i++)
		{
			int w=z[u][i].w;
			int v=z[u][i].to;
			if (ans[u]+w<ans[v])
			{
				ans[v]=ans[u]+w;
				q.push({ans[v],v});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>t;
	cost.resize(n+5);
	z.resize(n+5);
	ans.resize(n+5);
	for (int i=0;i<n;i++)
	{
		cin>>cost[i];
	}
	while (m--)
	{
		int num;
		cin>>num;
		if (num==2)
		{
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			z[a-1].push_back({c-1,b+d});
			z[c-1].push_back({a-1,b+d});
		}
		else
		{
			while (num--)
			{
				int a,b;
				cin>>a>>b;
			}
		}
	}
	while (t--)
	{
		int begin,end;
		cin>>begin>>end;
		find(begin-1);
		cout<<ans[end-1]+cost[begin-1]+cost[end-1]<<endl;
	}
	return 0;
}
