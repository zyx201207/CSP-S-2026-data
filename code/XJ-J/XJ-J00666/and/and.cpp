#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[105],b[100004];
	cin>>n>>m;
	b[1]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int o=1;o<=n;o++){
				for(int k=1;k<m;k++)
				{
					b[i*j*o]=a[i]&a[i+j];
				}
			}
		}
	}
	int x=0;
	for(int i=1;i<=n*n*n;i++)
	{
		if(b[i]>b[x])
		{
			x=i;
		}
	}
	cout<<b[x];
	return 0;
}