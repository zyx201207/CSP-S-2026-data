#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,Q,ans,x,y;
int w[500005],k,a[505][1005],t[505][1005];
struct node{
	int v,w;
};
struct Way{
	node N;
	int w;
};
vector<vector<node>>g[500005];
vector<vector<int>>s[505];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[k][j]>>t[k][j];
			if(j==1)continue;
			s[k].pushback(a[k][j]);
			g[a[k][j]].push_back({a[k][j-1],t[k][j]});
			g[a[k][j-1]].push_back({a[k][j],t[k][j]});
		}
	}
	for(int i=1;i<=Q;i++)
	{
		cin>>x>>y;
		ans=0;
		queue<Way>q;
		q.push({x,w[x]+w[y]},-1);
		while(!q.empty())
		{
			for(node j:g[x])
			{
				if(g[])
			}
		}
	}
	return 0;
}
