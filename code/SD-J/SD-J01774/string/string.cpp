#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, a[200005], ans;
char c[200005];
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
	}
	int i = 1, j = n;
	while(1)
	{
		if(i >= j)
		{
			break;
		}
		if(a[i] > a[j])
		{
			if(c[i] != c[j])
			{
				ans += a[j];
			}
			a[i] -= a[j];
			j--;
		}
		else if(a[i] == a[j])
		{
			if(c[i] != c[j])
			{
				ans += a[i];
			}
			j--; 
			i++;
		}
		else
		{
			if(c[i] != c[j])
			{
				ans += a[i];
			}
			a[j] -= a[i];
			i++;
		}
	}
	cout << ans;
	return 0;
}

