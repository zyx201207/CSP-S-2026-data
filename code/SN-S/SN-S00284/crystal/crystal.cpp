#include <bits/stdc++.h>
using namespace std;

int n,maxn = 0;
long long m,a[500005],sa[500005];

bool cmp(long long x,long long y)
{
	return x > y;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)sa[i] = sa[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
//		long long cnt = 0,j = 1;
//		for(;j<=n+1-i;j++)
//		{
//			cnt += a[i] - a[i+j-1];
//			if(cnt > m)break;
//		}
//		cout << j-1 << endl;
		int ans = 1,l = 1,r = n-i+1;
		while(l <= r)
		{
		   	int mid = (l+r)/2;
			if(1ll*a[i]*mid-1ll*(sa[i+mid-1]-sa[i-1]) > m)
			{
				r = mid-1;
				ans = mid;
			}
			else
			{
				l = mid+1;
			}
		}
		if(ans == 1)ans = n-i+2;
		maxn = max(maxn,ans-1);
	}
	cout << maxn << endl;
	return 0;
}
