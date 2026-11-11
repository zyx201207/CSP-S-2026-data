#include <bits/stdc++.h>
using namespace std;

#define int long long

int a[200005];
bool canch[200005], pre[200005];

signed main()
{
	memset(canch, 1, sizeof(canch));
	memset(pre, 1, sizeof(pre));
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int sum = 0;
	bool usep = false;
	for(int i = 30; i >= 0; i--)
	{
		int cnt = 0;
		for(int j = 1; j <= n; j++)
		{
			if(usep) canch[j] = (canch[j] && pre[j]);
			if(canch[j] && (a[j] & (1ll << i)) != 0ll)
				cnt++, pre[j] = true;
			else if(canch[j]) pre[j] = false;
		}
		if(cnt >= m)
			usep = true, sum += (1ll << i);
	}
	cout << sum << '\n';
	 
	return 0;
}
//rp++
