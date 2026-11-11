#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],sum,ans,maxa,mina = 0x3f3f3f3f;
bool cmp(long long x ,long long y)
{
	return x < y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		maxa = max(a[i],maxa);
		mina = min(a[i],mina);
	}
	sort(a+1,a+n+1,cmp);
	for (long long mid =mina;mid <= maxa;mid++)
	{
		long long m1 = m;
		sum = 0;
		for (int i = 1;i <= n;i++)
		{
			if (mid < a[i]||m1-mid+a[i]<0)
			{
				break;
			}
			sum ++;
			m1 -= (mid - a[i]);
		}
		ans = max(ans,sum);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
