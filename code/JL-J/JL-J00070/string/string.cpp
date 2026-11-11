#include <bits/stdc++.h>
using namespace std;
long long int n, ans;
const int N = 2e5 + 5;
long long int a[N];
char b[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(long long int i = 1; i <= n; i++)
	{
		long long int x;
		cin >> x;
		char y;
		cin >> y;
		a[i] = x;
		b[i] = y;
	}
	for(int i = 1, j = n; i <= n / 2 || j >= n / 2; i++, j--)
	{
		if(b[i] != b[j])
		{
			if(a[i] >= a[j])
			{
				ans += a[j];
				a[i] -= a[j];
				a[j] = 0;
				if(a[i] != 0)
					i--;
			}
			else
			{
				ans += a[i];
				a[j] -= a[i];
				a[i] = 0;
				j++;
			}
		}
		else
		{
			if(a[i] >= a[j])
			{
				a[i] -= a[j];
				a[j] = 0;
				if(a[i] != 0) i--;
			}
			else
			{
				a[j] -= a[i];
				a[i] = 0;
				j++;
			}
		}
	}
	//for(int i = 0; i < n; i++)
		//cout << b[i] << endl;
	cout << ans;
	return 0;
}
