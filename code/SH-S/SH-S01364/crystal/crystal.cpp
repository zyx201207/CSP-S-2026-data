#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
long long n,m,a[N],ans,cnt,maxi;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	maxi = n;
	for (int i = n;i >= 1;i--)
	{
		cnt += a[maxi]-a[i];
		if (cnt > m)
		{
			ans = max(ans,maxi-i);
			while (cnt > m)
			{
				cnt -= (maxi-i)*(a[maxi]-a[maxi-1]);
				maxi--;
			}
		}
	}
	ans = max(ans,maxi);
	cout << ans;
	
	return 0;
}
