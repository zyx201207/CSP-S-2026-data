#include <bits/stdc++.h>
using namespace std;

long long n,m,a[200005];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (long long i = 1;i <= n;++i) cin >> a[i];
	sort(a + 1,a + 1 + n);
	reverse(a + 1,a + 1 + n);
	long long ans = a[1];
	for (long long i = 2;i <= m;++i) ans = ans & a[i];
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}