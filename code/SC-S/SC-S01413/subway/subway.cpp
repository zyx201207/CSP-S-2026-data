#include<bits/stdc++.h>
using namespace std;
const int N=501,M=5e5+1;//n条线，m个点，q个询问 
int c,n,m,d,q;
int w[M];
int k[N];
vector<int> a[N],t[N];//第i个线有几个点，分别是啥，从 点到线/线到点 的时间 
int dl[M][25],dlt[M][25],cnt[M];//第i个点的几条线，线的个数 
int dp[N][N];
void DP()
{
	for(int k=1;k<=n;k++)
		for(int j=1;j<=n;j++)
			for(int i=1;i<=n;i++)
				if(i!=j&&j!=k) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int in1,in2;
			cin>>in1>>in2;
			a[i].push_back(in1);
			t[i].push_back(in2);
			dl[in1][++cnt[in1]]=i;
			dlt[in1][cnt[in1]]=in2;
		}
	}
	memset(dp,0x3f3f3f3f,sizeof dp);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<a[i].size();j++)
		{
			int dist=a[i][j],tim=t[i][j];
			for(int l=1;l<=cnt[dist];l++) dp[i][dl[dist][l]]=dp[dl[dist][l]][i]=tim+dlt[dist][l];
		}
	}
	DP();
	for(int i=1;i<=q;i++)
	{
		int ans=0x3f3f3f3f,x,y;
		cin>>x>>y;
		for(int j=1;j<=cnt[x];j++)
			for(int k=1;k<=cnt[y];k++)
			{
				int l1=dl[x][j],l2=dl[y][k];
				if(l1==l2) ans=min(ans,dlt[x][j]+dlt[y][k]);
				else ans=min(ans,dp[l1][l2]+dlt[x][j]+dlt[y][k]);
			}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
