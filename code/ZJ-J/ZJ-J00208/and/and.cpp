#include <bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	if(n == m)
	{
		long long sum = 1;
		for(int i = 1;i <= n;i++)
		{
			sum = (sum & a[i]);
		}
		cout << sum;
		return 0;
	}
	else if(n == 1)
	{
		cout << a[n];
		return 0;
	}
	//2 ^ 30 = 1073741824
	//         1000000000
	return 0;
}
