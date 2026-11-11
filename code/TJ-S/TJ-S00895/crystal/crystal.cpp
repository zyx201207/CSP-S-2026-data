#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
long long m;
long long a[500001];
long long qzh[500001];
int anss = 0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++)
	{
		qzh[i] = qzh[i - 1] + a[i];
		int l = 1,r = n,ans = 0;
		while(l <= r)
		{
			int mid = (l + r) / 2;
			if(a[i] * (i - mid + 1) - (qzh[i] - qzh[mid - 1]) <= m)
			{
				r = mid - 1;
				ans = (i - mid + 1);
			}
			else l = mid + 1;
		}
		anss = max(anss,ans);
	}
	cout << anss;
}
