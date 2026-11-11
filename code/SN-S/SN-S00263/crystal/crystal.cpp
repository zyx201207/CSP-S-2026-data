#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 500000;
int n, m;
int a[MAXN + 5];
int sum[MAXN + 5];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	if(n * a[n] - sum[n] <= m)
	{
		cout << n;
		return 0;
	}
	for(int i = 1; i <= n - 1; i++)
	{
		int Sum = i * a[i] - sum[i];
		int _Sum = (i + 1) * a[i + 1] - sum[i + 1];
		if(Sum <= m && m < _Sum)
		{
			cout << i;
			break;
		}
	}
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
