#include <bits/stdc++.h>
using namespace std;
long long m, a[500005];
//long long ch, cnt[200100];
int n;
bool b = 1;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	//~ ch = a[2] - a[1];
	//~ for(int i = 3; i <= n; i++)
	//~ {
		//~ if(a[i] - a[i - 1] != ch)
		//~ {
			//~ b = 0;
			//~ break;
		//~ }
	//~ }
	//~ if(b)
	//~ {
		//~ int sum = 0, i = 1;
		//~ for(; sum + i * ch <= m; i++)
		//~ {
			//~ sum += i * ch;
		//~ }
		//~ i--;
		//~ cout << min(n, i);
	//~ }
	//~ else
	//~ {
	long long sum = 0;
	int st = 1, maxn = 0;
	for(int i = 2; i <= n; i++)
	{
		sum += (a[i] - a[i - 1]) * (i - st);
		if(sum <= m)
			maxn = max(maxn, i - st + 1);
		while(sum > m)
		{
			sum -= a[i] - a[st];
			st++;
			maxn = max(maxn, i - st + 1);
		}
	}
	cout << maxn;
	//~ }
	return 0;
}
/*56
 *
 * 1379
 * 1589
 * 134455689
 * 369
 * 123
 * 358421468
*/
