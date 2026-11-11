#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int cnt,c,n,m,d,q,w[500005],k;
int g[505][505];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i,j;
	cin>>c>>n>>m>>d>>q;
		for(i=1;i<=m;i++)
		{
			cin>>w[i];
		}
		for(i=1;i<=n;i++)
		{
			int u,v,t1,t2;
			cin>>k;
			if(k!=1)
			{
				cin>>u>>t1>>v>>t2;
				g[u][v]=t1+t2;
				g[v][u]=t1+t2;
			}
			else
			cin>>u>>t1;
		}
	int x,y;
	for(i=1;i<=q;i++)
	{
		cin>>x>>y;
		cout<<g[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}

