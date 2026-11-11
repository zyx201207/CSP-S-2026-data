#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll n , m , a[N];
int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	sort(a + 1 , a + n + 1);
	ll sum = a[1]; int res = 1;
	for(int i = 2 , j = 1 ; i <= n ; i++)
	{
		while(j < i && ll(i - j) * a[i] - sum > m)
		{
			sum -= a[j];
			j++;
		}
		res = max(res , i - j + 1);
		sum += a[i];
	}
	cout << res << "\n";
	return 0;
}