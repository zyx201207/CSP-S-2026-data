#include <iostream>
#include <algorithm>
using namespace std;
int a[200005];
bool cmp(int a, int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	bool delta = true;
	cin >> n >> m;
	int i;
	for(i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i]!=i-1)delta = false;
	}
	if(delta)
	{
		int ans = a[n];
		for(int i = n-1;i>=n-m+1;i--)
		{
			ans = ans & a[i];
		}
		cout << ans;
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		cout << a[m];
	}
	return 0;
}
