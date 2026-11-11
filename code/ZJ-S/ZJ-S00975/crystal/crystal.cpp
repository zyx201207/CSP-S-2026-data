#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n , m , a[500050] , ans[500050] , haom[500050] , ans2 = 1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1 , a + 1 + n);
	ans[1] = 1;
	haom[1] = 0;
	for(int i = 2; i <= n; i++)
	{
		ans[i] = ans[i - 1] + 1;
		haom[i] = haom[i - 1] + (ans[i] - 1) * (a[i] - a[i - 1]);
		while(haom[i] > m)
		{
			haom[i] -= a[i] - a[i - ans[i] + 1];
			ans[i]--;
		}
		if(ans[i] > ans2)
		{
			ans2 = ans[i];
		}
	}
	cout << ans2;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
