#include<bits/stdc++.h>
using namespace std;
#define N 505
#define U 5005
#define ll long long
const int M=5e5+5;
int n,m,q,w[M],g[U][U];
int t[M],a[M];
void add(int u,int v,int k)
{
	g[u][v]=g[v][u]=k;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=m;++i)g[i][i]=0;
	for(int i=1;i<=n;++i)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;++j)cin>>a[j]>>t[j];
		for(int j=1;j<k;++j)
		    add(a[j],a[j+1],t[j]+t[j+1]);
	}	
	for(int i=1;i<=m;++i)
	for(int j=1;j<=m;++j)
	for(int k=1;k<=m;++k)
	    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<g[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}

