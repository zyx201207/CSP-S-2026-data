#include<bits/stdc++.h>
using namespace std;

long long n, m, ans,al;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	long long a[n+5];
	for(long long i = 0; i < n; i++)cin >> a[i];
	sort(a, a+n);
	al = n-1;
	ans = a[al];
	al--;
	for(long long i = 1; i < m; i++)
	{
		ans = ans&a[al];
		al--;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
