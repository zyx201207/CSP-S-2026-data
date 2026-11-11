#include <bits/stdc++.h>
using namespace std;

long long w[100001];
long long setn[100001][501] = {0}; 
long long graph[501][501] = {0};
int main() 
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	memset(graph,127,sizeof(graph));
	memset(setn,127,sizeof(setn));
	for(long long i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(long long i = 1;i <= n;i++)
	{
		long long k;
		cin >> k;
		graph[i][i] = 0;
		for(long long j = 1;j <= k;j++)
		{
			long long a,t;
			cin >> a >> t;
			setn[a][i] = t;
			setn[a][0] ++;
		}
	}
	for(long long i = 1;i <= m;i++)
	{
		if(setn[i][0] < (1ll << 50))
		{
			continue;
		}
		for(long long j = 1;j <= n;j++)
		{
			if(setn[i][j] > (1ll << 50))
			{
				continue;
			}
			for(long long k = 1;k <= n;k++)
			{
				if(setn[i][k] <= (1ll << 50))
				{
					graph[j][k] = graph[k][j] = min(graph[j][k],setn[i][j] + setn[i][k]);
				} 
			}			
		}
	}
	for(long long k = 1;k <= n;k++)
	{
		for(long long i = 1;i <= n;i++)
		{
			for(long long j = 1;j <= n;j++)
			{
				if(graph[i][k] < (1ll << 50) && graph[k][j] < (1ll << 50) && graph[i][j] > graph[i][k] + graph[k][j])
				{
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
	for(long long i = 1;i <= q;i++)
	{
		long long s,t;
		cin >> s >> t;
		long long res = 1ll << 60;
		for(long long j = 1;j <= n;j++)
		{
			if(setn[s][j] > (1ll << 50))
			{
				continue;
			}
			for(long long k = 1;k <= n;k++)
			{
				if(setn[t][k] < (1ll << 50))
				{
					long long ans = setn[s][j] + setn[t][k] + graph[j][k];
					res = min(res,ans);
				}
			}
		}	
		res += w[s] + w[t];
		cout << res << endl;	
	}
	return 0;
}
