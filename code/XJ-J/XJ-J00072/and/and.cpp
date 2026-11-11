#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];

int And(int a,int b)
{
	return a&b;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int ans = a[n];
	for (int i=1;i<=m-1;i++)
	{
		ans = And(ans,a[n-i]);
	}
	cout << ans;
	return 0;
}
