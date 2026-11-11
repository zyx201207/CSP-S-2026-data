#include<bits/stdc++.h>
using namespace std;
#define nmax 509
#define mmax 500009
#define greatest 2000000009
int c,n,m,q,d;
long long t[nmax][29];
long long w[mmax];
long long line[nmax][nmax];
void search();
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	vector<vector<int> >own(m+1);//第i个站台拥有的路线集合own[i] 
	
	for(int i =1;i<=n;i++)
		for(int j=1;j<=n;j++)
			line[i][j] = greatest;	
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);	
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		line[i][i] = 0;
		for(int j=1;j<=k;j++)
		{
			int station,www;
			scanf("%d %d",&station,&www);
			t[i][station]=www;
			own[station].push_back(i);
			for(int v=0;v<own[station].size();v++)
			{
				long long cost = t[i][station] + t[own[station][v]][station];
				cost = min(cost,line[i][own[station][v]]);
				line[i][own[station][v]] = cost; 
				line[own[station][v]][i] = cost;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			long long mini=line[i][j];
			for(int k=1;k<=n;k++)
			{
				mini = min(mini,line[i][k]+line[k][j]);
			}
			line[i][j] = mini;
			line[j][i] = mini;
		}
	}
	int x,y;
	for(int u=1;u<=q;u++)
	{
		scanf("%d %d",&x,&y);
		long long ans=w[x]+w[y];
		long long mini=greatest;
		for(int i=0;i<own[x].size();i++)
			for(int j=0;j<own[y].size();j++)
				mini = min(mini,line[own[x][i]][own[y][j]]+t[own[x][i]][x]+t[own[y][j]][y]);
		ans+=mini;
		printf("%lld\n",ans);
	}
	return 0;
}
