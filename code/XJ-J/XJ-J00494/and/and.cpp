#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m,a[10000],max;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++ )
	{
		for(int j=1;j<=m;i++)
		{
			if(a[i] and a[i+1]>a[i+1] and a[i+2])
			{
				max=a[i] and a[i+1];
			}
		}
	}
	cout<<max;
	return 0;
}