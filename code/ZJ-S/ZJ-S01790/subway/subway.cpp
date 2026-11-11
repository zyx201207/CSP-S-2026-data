#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int c,n,m,d,q,u,v;
int w[N];
vector <int> road[N];
vector <int> ti[N],xian[N];
int ans=0,res=1e18;
void dfs(int x,int t,bool mark)
{
	int i=0;
	for(;i<road[t].size();i++)
	{
		if(road[t][i]==x) 
		{
			break;
		}
	}
	if(mark) {ans+=ti[t][i];}
	i++;
	int nxt=road[t][i];
	if(nxt==v)
	{
		ans+=ti[t][i];
		return;
	}
	for(int j=0;j<xian[nxt].size();j++)
	{
		if(xian[nxt][j]==t)  {dfs(nxt,t,0);}
		else 
		{
			ans+=ti[t][i];
			dfs(nxt,xian[nxt][j],1);
		}
	}
	return;
}
signed main(void)
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;cin>>a>>t;
			road[i].push_back(a);
			ti[i].push_back(t);
			xian[a].push_back(i);
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>u>>v;
		res=1e18;
		for(int j=0;j<xian[u].size();j++)
		{
			ans=0;
			ans+=w[u]+w[v];
			dfs(u,xian[u][j],1);
			res=min(res,ans);
		}
		cout<<res<<"\n";
	}
	
}
