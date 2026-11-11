#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int a[N]; char c[N];
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	int n; cin >> n;
	int len = 0;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i] >> c[i];
		len += a[i];
	}
	
	int ai = 0, aj = 0;
	char ci = '0', cj = '0';
	int ans = 0, cnt = 0;//ans: 失配次数 cnt: 匹配次数 
	int i = 0, j = n + 1;//two-point
	int mid = (1 + len) >> 1;
	if ((len & 1) == 1) mid --;//奇数的中间不用配 
	
	while (cnt < mid)
	{
		if (!aj)
		{
			j --;
			aj += a[j]; cj = c[j];
		}
		while (aj)
		{
			if (cnt >= mid) break;
			if (!ai) 
			{
				i ++;
				ai += a[i]; ci = c[i]; 
			} 
			if (aj >= ai)
			{
				aj -= ai;
				if (cj != ci)
					ans += ai;
				cnt += ai;
				ai = 0;
			}
			else
			{
				ai -= aj;
				if (cj != ci)
					ans += aj;
				cnt += aj;
				aj = 0;
			}
		}
	}
	cout << ans; 
	return 0;
}
