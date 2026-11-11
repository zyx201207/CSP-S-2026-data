#include <iostream>
#include <algorithm>
using namespace std;
int n,flag[114514];
long long m,a[500005],maxx = -1;
long long check(long long mid,long long x)
{
	//a[mid]
	long long ans = 0;
	for (int i = mid - 1;i >= 1;i--)
	{
		if (x - (a[mid] - a[i]) >= 0)
		{
			x -= (a[mid] - a[i]);
			ans++;
		}
		else
		{
			break;
		}
	 }
	 return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
//	if (a[n] <= 100005)
//	{
//		for (int i = 1;i <= n;i++)
//		{
//			flag[a[i]]++;
//		}
//	}
	long long l = 1,r = n;
	while (l < r)
	{
		long long mid = (l + r) / 2;
		if (check(mid,m) > maxx)
		{
			maxx = check(mid,m);
			l = mid;
		}	
		else
		{
			r = mid;
		}
//		cout << l << " " << r << " " << maxx << "\n";
	}
	cout << maxx + 1;
	return 0;
 } 
