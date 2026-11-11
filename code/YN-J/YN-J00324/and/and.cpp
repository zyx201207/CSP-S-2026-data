#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int n, m;
int a[MAXN], cntA;
int is1[MAXN], cntIs1;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	cntA = n;
	int res = 0;
	for(int i = 30; i >= 0; i--)
	{
		res <<= 1;
		cntIs1 = 0;
		for(int j = 1; j <= cntA; j++)
		{
			int bit = (a[j] >> i) & 1;
			if(bit) is1[++cntIs1] = a[j];
		}
		if(cntIs1 >= m)
		{
			for(int j = 1; j <= cntIs1; j++) a[j] = is1[j];
			cntA = cntIs1;
			res |= 1;
		}
	}
	cout << res;
	return 0;
}