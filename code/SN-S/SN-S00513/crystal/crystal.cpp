//李雨轩 SN-S00513 陕西延安中学 
#include <bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >>m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
	}
	if (n<=5000)
	{
		long long ans=0;
		for (int i=2;i<=n;i++)
		{
			long long num=1;
			int x=m;
			for (int j=i;j<=n;j++)
			{
				if (x-(b[j]*(j-1))<0) break;
				else 
				{
					x-=b[j]*(j-1);
					num++;
				}
			}
			ans=max(ans,num);
		}
		cout << ans;
	}
	else if (n>5000)
	{
		long long x=m,num=1;
		for (int i=2;i<=n;i++)
		{
			if (x-(b[i]*(i-1))<0) break;
			else
			{
				x-=b[i]*(i-1);
				num++;
			}
		}
		cout << num;
	}
	return 0;
}
