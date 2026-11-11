#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[20005];
long long ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) 
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	ans = a[n] & a[n - 1];
	for(int i = 3;i <= m;i++)
	{
		ans = ans & a[i];
	}
	cout << ans;
	return 0;
}
