#include<bits/stdc++.h>
using namespace std;

#define int long long
const int RP = 0x3f3f3f3f;
int n, m;
const int N = 5e5 + 10;
int a[N];
int b[N], cnt;
int num[N];
int ans, res;

signed main()
{
freopen("crystal.in", "r", stdin);
freopen("crystal.out", "w", stdout);
ios::sync_with_stdio(false);
cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++)
	{
		if(a[i] != a[i - 1]) b[++ cnt] = a[i];
		num[cnt] ++;
	}
	for(int i = 1; i <= cnt; i ++) ans = max(ans, num[i]);
	int sum = 0, length = 0;
	for(int i = 1, j = 2; j <= cnt; j ++)
	{
		length += num[j - 1];
		sum += (b[j] - b[j - 1]) * length;
		while(sum > m && j - i > 1)
			sum -= num[i] * (b[j] - b[i]),
			length -= num[i], i ++;
		if(sum <= m)
		{
			res = length + num[j];
			if(i > 1) res += min(num[i - 1], (m - sum) / (b[j] - b[i - 1]));
			ans = max(ans, res);
		}
		else ans = max(ans, (m - sum) / (b[j] - b[j - 1]));
	}
	cout << ans << endl;
	
	return 0;
}
