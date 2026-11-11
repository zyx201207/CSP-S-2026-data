#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;

ll n , m , a[N] , d[N] , ans = 1;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	
	sort(a + 1 , a + n + 1);
	
	for(int i = 2 ; i <= n ; i++)
	{
		d[i - 1] = a[i] - a[i - 1];
	}
	
	for(int i = 1 ; i < n ; i++)
	{
		d[i] = d[i - 1] + i * d[i];
	}
	
	for(int i = 1 ; i < n ; i++)
	{
		// cout << d[i] << " ";
		if(m < d[i])
		{
			break;
		}
		ans++;
	}
	
	cout << ans;
	
	return 0;	
}
