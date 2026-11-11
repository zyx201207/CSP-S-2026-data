#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int w[500005];
int vis[500005];
vector<pair<int,int>> line[505];
vector<int> inl[500005];
long long ans=1e9;
void dfs(int u,int v,long long value)
{
	if(value>=ans) return ;
	if(u==v) 
	{
		ans=min(ans,value);
		return ;
	}
	for(int i=0;i<inl[u].size();i++)
	{
		for(int j=0;j<line[inl[u][i]].size();j++)
		{
			if(line[inl[u][i]][j].first!=u)
			{
				dfs(line[inl[u][i]][j].first,v,(line[inl[u][i]][j].first == inl[u][i] ?value:value+line[inl[u][i]][j].second));
			}
		}
	}
}
int main() 
{
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
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
		for(int i=1;i<=k;i++)
		{
			int u,t;
			cin>>u>>t;
			line[i].push_back({u,t});
			inl[u].push_back(i);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		ans=1e9;
		dfs(l,r,0);
		cout<<ans+w[l]+w[r]<<endl;
	}
}
