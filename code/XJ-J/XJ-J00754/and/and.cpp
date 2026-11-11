#include <bits/stdc++.h>
using namespace std;
long long n,x,a[100005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>x;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long maxc=-1;
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=x+1;j++)
		{
			long long num=a[j] & a[i];
			if (num>maxc)
			{
				maxc=a[j] & a[i];
			}
		}
	}
	cout<<maxc;
	return 0;
}