#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 +10;
int n,m,a[N],cf[N],num;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	for(int i = 1;i < n;i++)
	{
		cf[i] = a[i + 1] - a[i];
	}
	int idx = 0;
	while(++num * cf[++idx] <= m)
	{
		m -= (cf[idx] * num);
	}
	cout << num;
	return 0;
}
