#include<bits/stdc++.h>
using namespace std;
long long n, ans;
long long a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	long long u = 1, v = n;
	while(u < v)
	{
		long long t = min(a[u], a[v]);
		if(c[u] != c[v])	ans += t;
		a[u] -= t, a[v] -= t;
		if(a[u] <= 0)	u++;
		if(a[v] <= 0)	v--;
	}
	cout << ans << endl;
	return 0;
}