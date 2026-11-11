#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 5e5 + 1;
int a[N];
int b[N];
int n, m;

bool check(int mid)
{
	int sum = 0;
	int ans = 0;
	for(int i = mid; i >= 1; i --)
	{
		sum += a[mid] - a[i];
	}
//	cout << mid << ':' << sum << endl;
	return sum <= m;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	int l = 0, r = n + 1;
	while(l + 1 < r)
	{
		int mid = l + r >> 1;
		if(check(mid)) l = mid;
		else r = mid; 
	} 
//	cout << l << endl;
	cout << l << endl;
	return 0;
}

