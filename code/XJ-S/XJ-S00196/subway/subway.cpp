#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
const int N=5e5+5;
int w[N];
struct edge
{
	int v,w;
};
int g[10005][10005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int v,t;
			cin>>v>>t;
			g[i][v]=t;
		}
	}
	int ans=0;
	for(int i=1;i<=q;i++)
	{
		int x1,x2;
		cin>>x1>>x2;
		cout<<w[x1]+g[x1][x2]+w[x2];
	}
	return 0;
}
