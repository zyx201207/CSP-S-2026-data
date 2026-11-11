#include <bits/stdc++.h>
#define int long long
using namespace std;
int re()
{
	char ch = getchar();
	int sum = 0, p = 1;
	while(!isdigit(ch)){if(ch == '-')p = -1; ch = getchar();}
	while(isdigit(ch)){sum = sum * 10 + (ch - '0'); ch = getchar();}
	return sum * p;
}
const int N = 5e5 + 5;
int n, k, a[N], s[N];
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = re(), k = re();
	for(int i = 1; i <= n; i++) a[i] = re();
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	
	int ans = 1;
	for(int i = 1; i <= n; i++)
	{
		int l = 1, r = i;
		while(l <= r)
		{
			int mid = (l + r) >> 1;
			if((i - mid + 1) * a[i] - (s[i] - s[mid - 1]) <= k) r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}
