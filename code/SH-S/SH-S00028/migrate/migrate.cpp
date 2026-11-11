#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

queue<long long> q;
long long cnt1[2000010], xing[2000010], maxn[2000010], minn[2000010], dis[2000010];
bool visn[2000010], tong[5010][5010];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, t;
	cin >> c >> t;
	for(long long T = 1; T <= t; T++)
	{
		long long n, d;
		cin >> n >> d;
		for(long long i = 1; i <= n; i++)
		{
			cin >> xing[i];
			maxn[i] = 0;
			minn[i] = 0x3f3f3f3f;
		}
		for(long long i = 1; i <= n; i++)
		{
			for(long long j = 1; j <= n; j++)
			{
				if(abs(xing[j] - xing[i]) <= d)
				{
					maxn[i] = max(maxn[i], j);
					minn[i] = min(minn[i], j);
				}
			}
		}
		if(n > 5000)
		{
			cout << 1ll * n * (n - 1) / 2;
		}
		long long ans = 0;
		for(long long i = 1; i <= n; i++)
		{
			memset(tong, false, sizeof(tong));
			for(long long j = 1; j <= n; j++)
			{
				visn[j] = false;
				dis[j] = 0x3f3f3f3f;
				cnt1[j] = 1; 
			}
			q.push(i);
			dis[i] = 0;
			while(!q.empty())
			{
				long long u = q.front();
				q.pop();
				visn[u] = true;
				for(long long k = minn[u]; k <= maxn[u]; k++)
				{
					if(k == u) continue;
					if(visn[k] == false) q.push(k);
					if(dis[k] == dis[u] + 1 && tong[k][u] == false)
					{
						cnt1[k]++;
						tong[k][u] = true;
					}  
					if(dis[k] > dis[u] + 1)
					{
						cnt1[k] = 1;
						tong[k][u] = true;
					}
					//cout << k << " " << cnt1[k] << "\n";
					dis[k] = min(dis[k], dis[u] + 1);
				}
			}
			for(long long j = 1; j <= n; j++)
			{
				//cout << dis[j] <<" ";
				if(cnt1[j] == 2) ans++;
			}
			//cout << "---------------" << i << "--------------" << endl;
		}
		cout << ans / 2 << "\n";
	}
	return 0;
}
