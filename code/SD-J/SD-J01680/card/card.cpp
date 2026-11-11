#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500010];
int dp[300010];
int ans[300010];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int len=1;
	while(len<=n)
	{
		int lst=len;
		memset(dp,0,sizeof(dp));
		for(int i=len;i<=n;i++)
		{
			dp[a[i]]++;
			if(dp[a[i]]>1)
			{
				lst=i;
				memset(dp,0,sizeof(dp));
				dp[a[i]]++;
			}
		}
		for(int i=lst;i<=n;i++)
		{
			ans[a[i]]++;
		}
		len++;
	}
	for(int i=1;i<m;i++)
	{
		printf("%d ",ans[i]);
	}
	printf("%d",ans[m]);
	return 0;
}

