#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int a[N];
long long sum, maxv;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	cin >> a[1];
	maxv = a[1], sum = a[1];
	for(int i = 2; i <= n; i ++)
	{
		cin >> a[i];
		maxv = max(maxv, 1ll * a[i]);
		sum = sum & a[i];
	}
	if(m == n) cout << sum << endl;
	else cout << maxv << endl;
	return 0;
} 
