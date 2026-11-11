#include<bits/stdc++.h>
using namespace std;
int n, a[200005];
char c[200005];
long long ans = 0;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i] >> c[i];
	int l = 1, r = n, l_a = a[1], r_a = a[n];
	char l_c = c[1], r_c = c[n];
	for(; l <= n && r >= 1; )
	{
		int tmp = min(l_a, r_a);
		if(l_c != r_c)ans += tmp;
		l_a -= tmp, r_a -= tmp;
		if(l_a == 0)l++, l_a = a[l], l_c = c[l];
		if(r_a == 0)r--, r_a = a[r], r_c = c[r];
	}
	cout << (ans >> 1);
	return 0;
}
