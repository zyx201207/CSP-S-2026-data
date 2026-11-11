#include<bits/stdc++.h>
#define ll long long
#define pair pair<int,int>
using namespace std;
const int inf=5e5+1;
int c,n,m,d,q,k,l,r,tot;
int w[inf];
bool vis[inf];
struct node
{
	vector<pair> e;
}s[inf];
vector<int>g[501];
void dfs(int num,int dep,int lin)
{
	if(lin>=tot)
	{
		return ;
	}
	if(dep==r)
	{
		tot=min(lin,tot);
		return ;
	}
	for(int i=0;i<g[num].size();i++)
	{
		int u=g[num][i],w;
		for(int j=0;j<s[u].e.size();j++)
		{
			if(s[u].e[j].first==num)
			{
				w=s[u].e[j].second;
			}
		}
		if(!vis[u])
		{
			for(int j=0;j<s[u].e.size();j++)
			{
				int v=s[u].e[j].first;
				vis[u]=1;
				dfs(v,u,lin+w);
				vis[u]=0;
			}
		}
	}
	return ;
}
void solve()
{
	int ans;
	cin>>l>>r;
	ans+=(w[l]+w[r]);
	int tot=1e9+1;
	for(int i=0;i<s[l].e.size();i++)
	{
		int car=s[l].e[i].first;
		dfs(car,l,s[l].e[i].second);
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int v,w;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>v>>w;
			s[v].e.push_back({i,w});
			g[i].push_back(v);
		}
	}
	while(q--)
	{
		solve();
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