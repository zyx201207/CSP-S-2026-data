#include<bits/stdc++.h>
#include<cstdio>
#include<stdio.h>
using namespace std;
const int N=5e5+5,M=500;
int c,n,m,d,q,w[N],k[M],a[M][M],t[M][M],head[M],wi[N],ti[N],vi[N],ne[N],num;
void add(int u,int v,int w)
{
	head[u]=ne[num];
	vi[num]=v;
	wi[num]=w;
	head[u]=num++;
}
int main()
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
		cin>>k[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
	}
	return 0;
} 