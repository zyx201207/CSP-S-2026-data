#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct node
{
	int x,id,t;
}a[505];
int w[500005];
int dp[5005][5005],jiao[5005][5005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	int k=1;
	for(int j=1;j<=n;j++)
	{
		int y;
		cin>>y;
		for(int i=k;i<=k+y;i++)
		{
			cin>>a[i].id>>a[i].t;
			a[i].x=j;
		}
		
		k+=y;
	} 
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(a[i].x==a[j].x)
			{
				dp[i][j]=0;
				continue;
			}
			if(a[i].id==a[j].id)
			{
				dp[i][j]=min(dp[i][j],a[i].t+a[j].t);
				jiao[a[i].x][a[j].x]=a[i].id;
				continue;
			}
			dp[i][j]=min(dp[i][j],dp[jiao[a[i].x][a[j].x]][jiao[a[i].x][a[j].x]]+a[i].t+a[j].t);
		}
	} 
	while(q)//6767676767676767676767676767676767676767676767sixsevenSIXSEVENSixSevenSiXsEvEn
	{
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]<<w[x]+w[y]<<endl;
		q--;
	}
	return 0;
 } 
