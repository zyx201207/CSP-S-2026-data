#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=5e5+5;
int c,n,m,d,h;//xxx，线数，站数，yyy，计划数 
int w[N];
int k[N];//第i条线经过数 
int a[N];//第i条线经过的站 
int t[N],st[N];//第i条线做的花费 
int g[505][505];
int x,y;//第i个计划的起始点
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&h);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k[i];j++)
		{
			for(int r=j+1;r<=k[i];r++)
			{
				if(g[a[j]][a[r]]==0)
				{
					g[a[j]][a[r]]=t[j]+t[r];
					g[a[r]][a[j]]=t[j]+t[r];
				}
				else
				{
					g[a[j]][a[r]]=min(g[a[j]][a[r]],t[j]+t[r]);
					g[a[r]][a[j]]=min(g[a[r]][a[j]],t[j]+t[r]);
				}
			}
		}
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(g[i][j]!=0) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				else g[i][j]=g[i][k]+g[k][j];
			}
		}
	}
	for(int i=1;i<=h;i++)
	{
		cin>>x>>y;
		cout<<g[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
 }
/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2






*/
