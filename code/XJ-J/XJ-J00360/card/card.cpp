#include <bits/stdc++.h>
using namespace std;
int n,m,a[10005],sum;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		int sum=0
		for(int j=1;j<=i;j++)
		{
			sum+=a[j];
		}
		cout<<sum;
	}
}