# include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e5 + 10;
LL n , m , a[N] , s[N];
bool check(LL d)
{
	for(LL i = d ; i <= n ; i ++)
	{
		if(a[i] * d - s[i] + s[i - d - 1LL] <= m) return 1;
	}
	return 0;
}
void solve()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i ++)
	{
		s[i] = s[i - 1] + a[i];
	}
	LL l = 0 , r = n;
	while(l < r)
	{
		LL mid = l + r + 1 >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l;
	return ;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	int t = 1;
	while(t --) solve();
	return 0;
} 
