#include<bits/stdc++.h>
using namespace std;
int a[100000][10000];
int w[10000];
int t[10000][10000];
int z[10000][10000];
int dp[10000][10000];
int v[10000][10000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,r,k,x,y;
	cin>>c>>m>>n>>d>>r;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=r;i++)
	{
		cin>>x>>y;
		z[x][y]=1;
	}
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<=m;j++) 
		{
			v[i][j]=t[i][j]+w[i]+w[j];
			
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
