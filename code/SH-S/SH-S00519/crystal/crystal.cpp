#include<bits/stdc++.h>
using namespace std;

long long a[500002];
long long qzh[500002];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i++) qzh[i] = qzh[i-1]+a[i];
	long long l = 1,r = n,mid,num = 1;
	while (l <= r)
	{
		mid = (l+r) / 2;
		bool flag = 0;
		for (int i = mid;i <= n;i++)
		{
			if (mid * a[i] - (qzh[i] - qzh[i-mid]) <= m)
			{
				flag = 1;
				break;
			}
		}
		if (flag) l = mid+1,num = mid;
		else r = mid-1;
	}
	cout << num;
	return 0;
}
