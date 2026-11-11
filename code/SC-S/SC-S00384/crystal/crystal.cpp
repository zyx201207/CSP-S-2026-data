#include <bits/stdc++.h>
#define maxn 500008
#define int long long
using namespace std;
int arr[maxn],arr2[maxn];

int check(int n1,int n,int m)
{
	int ans = 0,l = 0;
	for (int i = 1;i <= n;i++)
	{
		if (arr[i] <= n1)
		{
			arr2[i] = arr[i];
			l = i;
		}
		else break;
	}
	sort(arr2 + 1,arr2 + 1 + l);
	for (int j = 1;j <= l;j++)
	{
		if (m >= (n1 - arr2[j]))
		{
			m = m - n1 + arr2[j];
			ans++;
		}
	}
	return ans;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int flag2 = 1,d;
	for (int i = 1;i <= n;i++) 
	{
		
		cin >> arr[i];
		if ((d != (arr[i] - arr[i-1])) && i > 2) flag2 = 0;
		if (i > 1)
		{
			d = arr[i] - arr[i-1];
		}
		
	}
	sort(arr + 1,arr + 1 + n);
	if (flag2)
	{
		if (d == 0)
		{
			cout << n;
			return 0;
		}
		m = m / d;
		int i = 1;
		while(i * (i + 1) <= 2 * m && i < n) i++;
		cout << i;
		return 0; 
	}
	int s = -1;
	for (int i = 1;i <= n;i++)
	{
		int p = check(arr[i],n,m);
		if (p > s) s = p; 
	}
	cout << s;
	return 0;
}