#include <bits/stdc++.h> 
using namespace std;
long long n,m,a[500005],b[500005],sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		b[a[i]]++;
	}
	sort(b + 1,b + n + 1);
	if (b[n] >= m)
	{
		cout << b[n];
		return 0;
	}
	sort(a + 1,a + n + 1);
	int c = a[1];
	for (int i = c;i <= n;i++)
		b[i] = 0;
	for (int i = 1;i <= m;i++)
	{
		sort(a + 1,a + n + 1);
		a[1]++;
	}
	for (int i = 1;i <= n;i++)
		b[a[i]]++;
	sort(b + 1,b + n + 1);
	cout << b[n];
	return 0;
}