#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005]={0};
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(a[j]<a[j+1])
			{
				int o=a[j];
				a[j]=a[j+1];
				a[j+1]=o;
			}
		}
		
	}
	int ma=a[1];
	for(int i=2;i<=m;i++)
	{
		ma=ma&a[i];
	}
	cout<<ma;
	return 0;
}