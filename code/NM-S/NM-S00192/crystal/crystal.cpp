#include <bits/stdc++.h>
using namespace std;
long long m,n,a[500005],sum,cnt;
//int dp[500005][]
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		long long m2=m;
		sum=0;
		for (int j=i;j>=1;j--)
		{
			if (m2<a[i]-a[j])
				break;
			m2-=a[i]-a[j];
			sum++;
		}
		cnt=max(cnt,sum);
	}
	cout<<cnt;
	return 0;
 }
