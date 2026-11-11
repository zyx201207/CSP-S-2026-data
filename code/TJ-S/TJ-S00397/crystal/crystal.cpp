#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,c=1,sum=0;
	long long m;
	cin>>n>>m;
	int a[n+5];
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if (sum/n==a[1] && a[1]==a[n])
	{
		cout<<n;
	}
	else
	{
		for (int i=1;i<n;i++)
		{
			if (m>=(a[2]-a[1])*i)
			{
				m-=(a[2]-a[1]*i);
				c+=1;
			} 
		}
		cout<<c;
	}
	return 0;
}
