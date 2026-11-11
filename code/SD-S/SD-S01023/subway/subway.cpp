#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;
int c,n,d,m,q;
int w[500005],x[5050];
long long dist[510][510]={2147483645},t[510][510]; 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	 
	for(int i=1;i<=m;i++)
	{
		dist[i][i]=0;
	}
	 
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&x[j]);
//			x[j][x]=1;//第j个线路上到第x个地铁站有路 
			scanf("%d",&t[x[j]][i]);//第x个地铁站到第i个线路 
		}
		
		for(int j=1;j<=k;j++)
		{
			for(int h=1;h<=k;h++)
			{
				if(j!=h && t[j][i]!=0 && t[h][i]!=0)
				{
					dist[j][h]=min(dist[j][h],t[j][i]+t[h][i]);
					dist[h][j]=dist[j][h];
				}
			}
		}
	}
	 
	 
	for(int i=1;i<=m;i++)
	{
		dist[i][i]=0;
	}
	 
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)//列举地铁站 
		{
			for(int g=1;g<=m;g++)//要经过哪个 
			{
				dist[i][j]=min(dist[i][j],dist[i][g]+dist[g][j]);
				dist[j][i]=dist[i][j];
			}
			
		}
	} 
	
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",w[x]+w[y]+dist[x][y]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
