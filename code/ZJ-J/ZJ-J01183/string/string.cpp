#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
long long l;

int a[N];
char ch[N];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> ch[i], l += a[i];
		
	long long i = 1, j = n, l1 = a[1], l2 = a[n], p = 0, ans = 0;
	char c1 = ch[i], c2 = ch[j];
	while (p < l && i < j)
	{
		int x = min(l1, l2);
		if (c1 != c2)
			ans += x;
			
		p += x;
		
		if (l1 > l2)
			l2 = a[--j], l1 -= x, c2 = ch[j];
		else if (l1 < l2)
			l1 = a[++i], l2 -= x, c1 = ch[i];
		else
			l1 = a[++i], l2 = a[--j], c1 = ch[i], c2 = ch[j];
	}
	
	cout << ans;
	
	return 0;
}