#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const int M=5e5+5;
ll w[M],t[M],ans=0;
int a[M],c,n,m,d,q;
ll dp[1005][1005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
			dp[i][j]=1e15;
		dp[i][i]=0; 
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j]>>t[j];
			for(int l=1;l<j;l++)
			{
				dp[a[j]][a[l]]=t[l]+t[j];
				dp[a[l]][a[j]]=t[l]+t[j]; 
			}
		}
	}
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dp[x][y]<<"\n";
	}
	return 0;
}