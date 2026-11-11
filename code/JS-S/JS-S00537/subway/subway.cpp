#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int c,n,m,d,q,w[maxn],ans;
struct Node
{
	int a,t;
};
vector<Node> g[maxn];
void dfs(int x,int s,int ti,int xr,int yr)
{
	if(s==yr)
	{
		ans=min(ans,ti);
		return;
	}
	for(int i=0;i<g[x][s].size;i++)
	{
		int p=g[x][s][i];
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		for(int j=1,a1,t1;j<=k;j++)
		{
			cin>>a1>>t1;
			g[i][a1].push_back();
		}
	}
	for(int i=1,xr,yr;i<=q;i++)
	{
		cin>>xr>>yr;

	}
	return 0;
}