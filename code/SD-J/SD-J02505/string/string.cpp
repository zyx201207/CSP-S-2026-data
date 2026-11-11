#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int a[N];
	char c[N];
	for (int i = 1;i <= n;i++)
		cin >> a[i] >> c[i];
	long long cnt = 0;
	int l = 1,r = n;
	while (l < r)
	{
		if (c[l] != c[r])
			if (a[l] < a[r])
				cnt += a[l];
			else
				cnt += a[r];
		if (a[l] <= a[r])	a[r] -= a[l],a[l] = 0;
		if (a[l] > a[r])	a[l] -= a[r],a[r] = 0;
		if (a[l] == 0)	l++;
		if (a[r] == 0)	r--;
	}
	cout << cnt;
	return 0;
}
