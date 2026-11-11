#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int MAXN = 2e5 + 5;
const int LOGA = 35;
int n, m, a[MAXN], pw2[LOGA];
vector <int> d[MAXN];
vector <int> xb[MAXN];
inline void init()
{
	pw2[0] = 1;
	for(int i = 1; i <= 30; i++)
	{
		pw2[i] = pw2[i - 1] << 1;
	}
	return ;
}
inline void solve(int x, int id)
{
	for(int i = 30; i >= 0; i--)
	{
		if(x >= pw2[i])
		{
			d[i].push_back(id);
			x -= pw2[i];
		}
	}
	return ;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	init();
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		solve(a[i], i);
	}
	int ans = 0;
	for(int i = 30; i >= 0; i--)
	{
		if(d[i].size() >= m)
		{
			int sum = (1 << i);
			for(int j : d[i])
			{
				xb[i].push_back(j);
			}
			for(int k = i - 1; k >= 0; k--)
			{
				for(int j : xb[k + 1])
				{
					if((a[j] >> k) & 1)
					{
						xb[k].push_back(j);
					}
				}
				if(xb[k].size() >= m)
				{
					sum += (1 << k);
				}
				else
				{
					break;
				}
			}
			ans = sum;
			break;
		}
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// 10:27 出的思路一然后 10:33 推翻了，本来以为会很难但是仔细一想 10:36 出思路二而且看起来十分正确 
// 10:50 WA但是修补方案有了（虽然思路简单但是写起来好麻烦啊） 
// 10:59 T3 AC.
