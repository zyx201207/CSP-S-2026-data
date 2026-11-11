#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[100],sum=0;
	char c[100];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]=a[n-i])
		{
			if(c[i]=c[n-i])
			{
				sum+=0;
			}
			else
			{
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}