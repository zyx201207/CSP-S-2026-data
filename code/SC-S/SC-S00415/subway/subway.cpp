#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e4+10;

int c,n,m,d,q;
int w[N];
int sub[N][510][2],dp[N][510];
int qwq[N];
map<int,map<int,int>> mp;
signed main()
{
	//freopen("test.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>sub[i][j][0]>>sub[i][j][1];
			mp[i][sub[i][j][0]]=1;
			qwq[i]=k;
		}
	}
	for(int i=1;i<=q;i++)
	{
		
		int st,en;
		cin>>st>>en;
		memset(dp,0x3f,sizeof dp);
		for(int j=1;j<=n;j++)
		{
			dp[st][j]=sub[st][j][1]+w[j];
		}
		for(int j=st;j<=en;j++)
		{
			for(int k=1;k<=n;k++)
			{
				int flag=0;
				for(int f=1;f<=qwq[k];f++)
				{
					if(mp[k][sub[k][f][0]]==1)
					flag=1,dp[j][sub[k][f][0]]=min(dp[j][sub[k][f][0]],dp[j-1][sub[j-1][f-1][0]]);
				}
				if(flag==0)
				{
					for(int f=1;f<=qwq[k];f++)
					dp[j][k]=min(dp[j][f],dp[j-1][sub[j-1][f-1][0]]+sub[k][f][1]);
				}
			}
		}
		int cnt=INT_MAX;
		for(int i=1;i<=n;i++)
		cnt=min(cnt,dp[en][i]);
		cout<<cnt<<"\n";
	}
	return 0;
}