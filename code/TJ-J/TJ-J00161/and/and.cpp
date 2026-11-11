#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, maxx = 0, a[30000005];
void fast()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
}
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	fast();
	cin>>n>>m;
	for (int i = 1;i <= n;i++)
		cin>>a[i];
	cout<<(a[1] & a[n]);
	return 0;
}
/*
bu hui:(
*/
