#include <bits/stdc++.h>
using namespace std;

long long n,m,a[200000],b[10000000],mx = -1,ans;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i];
		b[a[i]]++;
		mx = max(mx,a[i]);
	}
	if(m == 1)
	{
		cout << mx;
		return 0;
	}
	for(long long i = 1;i <= mx;i++)
	{
		if(b[i] >= m)
			ans = max(ans,i);
	}
	cout << ans;
	return 0;
}
