#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int c;
int t;
string s;
long long d;
long long n;
long long dif;
long long x[2000010];
int dp[5010][5010]; //dp[i][j]表示从i号岛到j号岛的最短路线长度 
bool dp1[5010][5010];
bool dp2[5010][5010];
int furthest[5010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	bool flag = true;
	while(t--)
	{
		cin >> n >> d;
		int fcur = 1;
		if(c == 0 || c == 11 || c == 12)
		{
//			getline(s);
//			int cur = 0;
//			int to = 1;
//			long long temp = 0;
//			while(true)
//			{
//				if('0' <= s[cur] && s[cur] <= '9')
//					temp = temp * 10 + (int)(s[cur]) - 48;
//				else if(s[cur] == ' ') {
//					x[to] = temp;
//					temp = 0;
//					to++;
//					if(to == 3) break;
//				}
//				cur++;
//			}
//			cout << x[2] << ' ' << x[1] << endl;
//			for(int i=0;i<=cur;i++)
//			{
//				cout << s[cur];
//			}
			for(int i=1;i<=n;i++)
			{
				cin >> x[i];
			}
			long long key = d/abs(x[2] - x[1]);
			long long ans = n - 2 * key + 1;
			if(ans < 0 || ans >= n-1) ans = 0;
			cout << ans << endl;
		}
		else 
		{
			for(int i=1;i<=n;i++)
			{
				cin >> x[i];
			}
			if(1)
			{
				int fcur = n;
				for(int i=n;i>=1;i--)
				{
					while(x[i] - x[fcur] <= d)
					{
						fcur--;
					}
					furthest[i] = fcur + 1;
					dp[i][i] = 0;
				}
				// dp
				for(int i=1;i<=n-1;i++)
				{
					for(int j=i+1;j<=n;j++)
					{
						int dp0 = 1e9;
						dp1[i][j] = false;
						dp2[i][j] = false;
						for(int pos = furthest[j];pos < j;pos++)
						{
							if(i > pos) continue;
							if(dp0 == dp[i][pos] + 1)
							{
								if(dp1[i][j]) {
									dp2[i][j] = true;
								}
								else {
									dp1[i][j] = true;
								}
							}
							else if(dp0 > dp[i][pos] + 1)
							{
								dp1[i][j] = false;
								dp2[i][j] = false;
								dp0 = dp[i][pos] + 1;
							}
						}
						dp[i][j] = dp0;
					}
				}
				// dp end
				long long cnt = 0;
				for(int i=1;i<=n-1;i++)
				{
					for(int j=i+1;j<=n;j++)
					{
						if(dp1[i][j] && (!dp2[i][j]))
						{
							cnt++;
						}
					}
				}
				cout << cnt << endl;
			}
		}
	}
	return 0;
}
