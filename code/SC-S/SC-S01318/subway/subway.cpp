#include <bits/stdc++.h>
using namespace std;
int ans=1e8;
int c,n,m,d,q,w[500005],k[500005],a[500005][500005],t[500005][500005];
vector<vector<int> > g;
int x,y;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	int T;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			T=t[i][j];
			g[j].push_back(i);
		}
	}
	while(q--)
	{
		cin>>x>>y;
		queue<pair<int,int> > q;
		q.push({x,0});
		while(!q.empty())
		{
			int na=q.front().first,nb=q.front().second;
			q.pop();
			if(na==y)
			{
				cout<<T*nb+w[x]+w[y]<<endl;
				break;
			}
			for(int i=0;i<g[na].size();i++)
			{
				for(int j=1;j<=k[g[na][i]];j++)
				{
					if(a[g[na][i]][j]!=na)
					{
						q.push({a[g[na][i]][j],nb+1});
					}
				}
			}
		}
	}
	return 0;
}