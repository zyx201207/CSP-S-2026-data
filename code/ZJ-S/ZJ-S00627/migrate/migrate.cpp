#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
const int INF = 1e8;
int n;
long long d;
int dp[N];
long long a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d %d",&c,&T);
	while(T--)
	{
		scanf("%d %lld",&n,&d);
		for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
		long long res = 0;
		if(n <= 8000)
		{
			for(int i = 1;i <= n;i++)
			{
				dp[i] = 0;
				int cur = i;
//				printf("%d: ",i);
				for(int j = i + 1;j <= n;j++)
				{
						dp[j] = INF;
					while(cur <= j && a[j] - a[cur] > d) cur++;
					if(cur <= j)
					{
						dp[j] = dp[cur] + 1;
					}
//					printf("%d ",dp[j]);
				}
//				printf("\n");
				cur = i;
				int lst = i;
				for(int j = i + 1;j <= n;j++)
				{
					while(cur <= j && a[j] - a[cur] > d) cur++;
					if(dp[j] != dp[j - 1]) lst = j - 1;
//					printf("!!%d %d: %d %d\n",i,j,cur,lst);
					if(lst - cur + 1 == 2)
					{
						
						res++;
					}
				}
			}
		}
		else
		{
			dp[1] = 0;
			int cur = 1;
			int lst = 1;
			for(int i = 1;i <= n;i++)
			{
				dp[i] = INF;
				while(a[i] - a[cur] > d && cur <= i) cur++;
				if(cur <= i) dp[i] = dp[cur] + 1;
				if(dp[i] == INF)
				{
					dp[i] = 0;
					cur = i;
					lst = i;
				}
				else
				{
					if(dp[i] != dp[i - 1]) lst = i - 1;
					if(lst - cur + 1 == 2) res += n - i + 1;
				}
			}
		
		}
		printf("%lld\n",res);
	}
	return 0;
}
