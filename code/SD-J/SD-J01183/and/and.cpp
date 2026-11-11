#include<iostream>
using namespace std;
int a[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==2)
	{
		int z=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
					z=max(z,a[i]&a[j]);
			}
		}
		cout<<z;
		return 0;
	}
	if(m==n)
	{
		int z=a[1];
		for(int i=2;i<=n;i++)
			z=z&a[i];
		cout<<z;
		return 0;
	}
	int z=-1;
	for(int i=1;i<=n;i++)
		z=max(z,a[i]);
	cout<<z;
	return 0;
}
