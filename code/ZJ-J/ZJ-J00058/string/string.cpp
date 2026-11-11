#include<bits/stdc++.h>
using namespace std;
int n, a[200005];
char c[200005];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	int l = 1, r = n;
	while (l <= r)
	{
		if (c[l] != c[r])
			ans += min(a[l], a[r]);
		if (a[l] == a[r])
			l++, r--;
		else if (a[l] < a[r])
			a[r] -= a[l], l++;
		else a[l] -= a[r], r--;
		
	}
	cout << ans;
	return 0;
}