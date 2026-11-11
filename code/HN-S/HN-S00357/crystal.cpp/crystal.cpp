#include <bits/stdc++.h>
using namespace std;
int cnt1=0,cnt2=0;
long long n,m,ans=0,a[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		b[i-1]=a[i]-a[i-1];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			ans+=b[j]; 
			if (ans<=m)
			{
				cnt1++;
			}
			else
			{
				j=n+1;
			}
		}
		cnt2=max(cnt1,cnt2);
		cnt1=0;
	}
	cout << cnt2+1;
	return 0;
}
