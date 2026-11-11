#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;  //n地铁线路数  m 地铁站数  d最多经过站数 q出行计划数  i线路编号 j地铁站编号  
	int t1[m];//每个站 口 到站 厅 的时间 
	int t2[n][m] ;//在第 a i,j 个地铁站处，从站 厅 走到第i条线路的站 台 需要的时间 
	int a[n][m]; //第n条路线经过的地铁站站数m 
	int k[n]; 
	int x[m],y[m];
	int t=0;
	for(int i=1;i<=m;i++)
	{
		cin>>t1[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j];
			cin>>t2[i][j];		
		}
		
	}
	for(int r=1;r<=q;r++)
	{
		cin>>x[r];
		cin>>y[r];
		t=t1[x[r]]+t2[r][r]+t2[r][r+1]+t1[x[r+1]];
	}
	
	
	
	
    return 0;
}
