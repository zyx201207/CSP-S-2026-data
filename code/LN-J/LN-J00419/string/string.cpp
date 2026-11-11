#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005],ans = 0;
	char c[200005];
	cin >> n;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1;i <= n;i++) cin >> a[i] >> c[i];
	int ptr1 = 1,ptr2 = n;
	while (ptr1 <= ptr2)
	{
		if (a[ptr1] > a[ptr2])
		{
			if (c[ptr1] != c[ptr2]) ans += a[ptr2];
			a[ptr1] -= a[ptr2];
			ptr2--;
		}
		else if (a[ptr1] < a[ptr2])
		{
			if (c[ptr1] != c[ptr2]) ans += a[ptr1];
			a[ptr2] -= a[ptr1];
			ptr1++;
		}
		else
		{
			if (c[ptr1] != c[ptr2]) ans += a[ptr1];
			ptr1++;
			ptr2--;
		}
	}
	cout << ans;
	return 0;
}
