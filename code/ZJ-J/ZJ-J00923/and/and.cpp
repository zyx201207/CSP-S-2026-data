#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const int MAXN = 2e5 + 10;
int a[MAXN][40];
bool visit[MAXN];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, maxw = 31;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int ai;
		cin >> ai;
		for(int j = 30; j >= 1; j--)
		{
			a[i][j] = ai % 2;
			ai /= 2;
			if(ai == 0)
			{
				maxw = min(maxw, j);
				break;
			}
		}
	}
	long long ans = 0;
	for(int i = maxw; i <= 30; i++)
	{
		int cnt = 0;
		for(int j = 1; j <= n; j++)
		{
			if(a[j][i] == 1 and !visit[j])
			{
				cnt++;
			}
			else visit[j] = true;
		}
		if(cnt >= m)ans += pow(2, 30 - i);
		else if(ans == 0)for(int j = 1; j <= n; j++)visit[j] = false;
	}
	cout << ans;
	return 0;
}
