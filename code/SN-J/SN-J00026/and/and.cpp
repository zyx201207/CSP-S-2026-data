#include <bits/stdc++.h> 
using namespace std;

long long n, m, minn, ans;
long long a[200005];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a, a+1);
	for(int i=0;i<n;i++)
	{
		for(int j = i;j<n;j++)
		{
			
			ans = (a[i] & a[j]);
			if(ans > minn)
			{
				minn = ans;
			}
		}
	}
	cout << ans;
	return 0;
} 
