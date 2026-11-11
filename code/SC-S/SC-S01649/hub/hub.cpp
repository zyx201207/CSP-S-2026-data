#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t,n,k,d,dpt;
vector<int>g[N];
void dfs(int u,int fa,int len)
{
	if(len>d)
	{
		d=len;
		dpt=u;
	}
	for(auto v:g[u])
	{
		if(v!=fa)
		{
			dfs(v,u,len+1);
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		d=0,dpt=1;
		dfs(1,0,0);
		d=0;
		dfs(dpt,0,0);
		cout<<(d+3)/4<<"\n";
	}
	return 0;
}