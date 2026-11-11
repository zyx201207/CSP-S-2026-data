#include<bits/stdc++.h>
using namespace std;

long long n, m. ans;
long long a[500005], b[500005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	long long x = a[n];
	for(int i = 1; i <= n; i++)
	{
		if(a[i] != x)ans++;
	}
	if(m == 1)cout << n;
	else cout << ans << " " << n; 
	
	return 0;
} 
