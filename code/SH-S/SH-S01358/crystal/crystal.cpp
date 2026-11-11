#include <iostream>
#include <algorithm>
using namespace std;
const int N = 500005;
long long m,a[N],s[N];
int n,l,r,mid,ans;
bool f(int x)
{
	bool b = false;
	for (int i = 1;i <= n - x;i++)
		if (s[i - 1] - s[i + x - 1] + x * a[i + x] <= m)
			b = true;
	return b; 
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
		s[i] = s[i - 1] + a[i];
	l = 0,r = n - 1;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (f(mid))
		{
			ans = mid + 1;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	cout << ans;
	return 0;
} 
