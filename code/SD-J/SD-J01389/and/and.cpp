#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	unsigned long long a[200005];
	cin >> n >> m;
	for (int i=1; i <= n; i++)
	{
		cin >> a[i];
	}
	unsigned long long ans = a[1];
	for (int i = 2; i <= m; i++)
	{
		ans &= a[i];
	}
	cout << ans;
	return 0;
}
