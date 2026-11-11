#include<bits/stdc++.h>
using namespace std;
long long n,m,k=1,minn=10000000000,c;
long long a[500050];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++)
	{
		long long k=a[i]-a[i-1];
		if (minn>k)
		{
			minn=k;
			c=i;
		}
	}
	int z=2;
	while (m>=(a[z]-a[z-1])*(z-1) && z<=n)
	{
		m-=(a[z]-a[z-1])*(z-1);
		k++;
		z++;
	}

	cout<<k;
	return 0; 
}
