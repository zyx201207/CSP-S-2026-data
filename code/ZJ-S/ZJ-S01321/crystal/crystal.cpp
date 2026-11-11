#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 5e5 + 10;
LL a[N], d[N];
LL s[N];
LL n, m;
int ans;

int main()
{
	//最后记得删掉// 
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++) s[i] = 1ll * a[i] + s[i - 1];
	for(int i = 1; i <= n; i ++)
	{
		int l = 1, r = i;
		while(l < r)
		{
			int mid = l + r + 1 >> 1;
			if(mid * a[i] - (s[i] - s[i - mid]) <= m) l = mid;
			else r = mid - 1;
		}	
		ans = max(ans, l);
	}
	cout << ans << endl;
	
	return 0;
}
