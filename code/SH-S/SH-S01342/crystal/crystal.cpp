#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[500005] , s[500005];
ll math(int i , int j)
{
	return a[i] * (i - j) - s[i - 1] + s[j - 1];
}
int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	int n; ll m; scanf("%d%lld" , &n , &m);
	for (int i = 1; i <= n; i++) scanf("%lld" , &a[i]);
	sort(a + 1 , a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int ans = 0;
	for (int i = 1 , j = 1; i <= n; i++)
	{
		while (j < i && math(i , j) > m) j ++;
		ans = max(ans , i - j + 1);
	}
	cout << ans;
	return 0;
}
