#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int x,y;
int k;
int main()
{
	freopen("subway.in",r,stdin);
	freopen("subway.out",w,stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m+5];
	int subw[m+5][m+5];
	memset(subw,0x3f3f3f3f,sizeof(subw));
	for(int i=1;i<=m;i++)
	  cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		int u[k+5];
		int num[k+5];
		for(int j=1;j<=k;i++)
		{
			cin>>u[j]>>num[j];
		}
		for(int j=2;j<=k;i++)
		{
			for(int z=2;z<=k;z++)
			{
				subw[u[j]][u[j-1]]=subw[u[j-1]][u[j]]=num[j]+num[j-1];
			}
		}
	}
	int dis[m+1][m+1];
	memset(dis,0x3f3f3f3f,sizeof(dis));
	for(int i=1;i<=n;i++)
	  dis[i][i]=0;
	for(int h=1;h<=q;h++)
	  {
	  	cin>>x>>y;
	  	for(int i=1;i<=n;i++)
	  	{
	  		for(int j=1;j<=n;j++)
	  		{
	  			for(int z=1;z<=n;z++)
	  			{
	  				dis[i][z]=min(subw[i][j]+subw[j][z],dis[i][z]);
				  }
			  }
		  }
		cout<<dis[x][y]+w[x]+w[y]<<endl;
	  }
	return 0;
 } 
