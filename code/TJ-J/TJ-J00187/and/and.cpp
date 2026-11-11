#include <bits/stdc++.h>
using namespace std;
long long a[200005],b[200005],num[200005],sum[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	long long cnt = 0;
	for(int i = 0;i <= n-1;i++)
	{
		cin >> a[i];
		b[i]=a[i];
		while(a[i]!=0)
		{
			num[i] = a[i]%2;
			a[i]/=2;
			b[i]=a[i];
		}
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= m;i++)
	{
		cin >> sum[i];
		if(num[i]==0&&num[i-1]==0)
		{
			sum[i]=0;
		}
		else if((num[i-1]==1&&num[i]==0)||(num[i-1]==0&&num[i]==1))
		{
			sum[i]=0;
		}
	    else
		{
			sum[i]=1;
		}
		sum[i]=!sum[i];
		for(int j = 0;j <= i-1;j++)
		{
			cnt+=sum[j]*pow(2,j);
		}
	}
	cout << cnt;
	return 0; 
}
