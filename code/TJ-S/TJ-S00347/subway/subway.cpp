#include <bits/stdc++.h>
#define int long long
using namespace std;
int w[500005];
int a[505][100005];
int t[505][100005];
int dp[100005];

struct Node 
{
	int l,r;
}nrr[100005];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		dp[i]=1e9;
	}
	for(int i=1;i<=n;i++)
	{
		int p;
		cin>>p;
		a[i][0]=p;
		t[i][0]=p;
		for(int j=1;j<=p;j++)
		{
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	int f;
	cin>>f;
	for(int i=1;i<=f;i++)
	{

		cin>>nrr[i].l>>nrr[i].r;
	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			for(int k=1;k<=a[i][0];k++)
			{
				for(int z=1;z<=a[j][0];z++)
				{
					if(a[i][k]==a[j][z])
					{
						dp[i]=min(dp[i],dp[j]+w[i]+t[i][k]);
					} 
				}
			}
		}
	}
	for(int i=1;i<=f;i++)
	{

		cout<<dp[nrr[i].r]-dp[nrr[i].l]<<endl;
	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}






