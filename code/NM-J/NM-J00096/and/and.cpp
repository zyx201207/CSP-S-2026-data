#include <bits/stdc++.h>
using namespace std;

int main()
{

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	long long n,m,a[10000005],maxn=0,num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	for(int i=1;i<=n;i++)
	{
		long long sum=a[i],b=i;
		while(m--)
		{
			num+=sum&a[b];
			b++;
		}
		if(maxn<=num)
		{
			maxn=num;
		}
	}

	cout<<maxn;
	return 0;
}
