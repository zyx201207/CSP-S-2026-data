#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5+10;
int n,l,cnt,a[N];
char c[N];

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		l += a[i];
	}
	for (int i = 1,j = n;i <= j;)
	{
		if (c[i] != c[j])
			cnt += min(a[i],a[j]);
		
		if (a[i] > a[j])
		{
			a[i] -= a[j];
			j--;
	    }
	    else if (a[i] == a[j])
	    {
	    	i++;
	    	j--;
		}
		else
		{
			a[j] -= a[i];
			i++;
		}
	}
	cout << cnt;
	return 0;
}
