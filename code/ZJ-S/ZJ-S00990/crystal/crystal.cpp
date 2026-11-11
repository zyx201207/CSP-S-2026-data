#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500004],ans,l = 1,r = 1,sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	while(r <= n)
	{
		sum += (a[r] - a[r - 1]) * (r - l);
		while(sum > m)
		{
			sum -= a[r] - a[l];
			l ++;
		}
		ans = max(ans,r - l + 1);
		r ++;
	}
	cout << ans;
	return 0;
}
