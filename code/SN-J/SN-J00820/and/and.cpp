#include <bits/stdc++.h>
using namespace std;
int a[200005],n,m;
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
		for(int i=1;i<=n;i++)
		{
			if(a[i]<a[i+1])
			{
				int k=a[i];
				a[i]=a[i+1];
				a[i+1]=k;
			}
		}
	}
	if(m==2)
	{
		cout<<a[m] and a[m-1];
	}
	if(m==3)
	{
		cout<<a[m] and a[m-1] and a[m-2];
	}
	if(m==4)
	{
		cout<<a[m] and a[m-1] and a[m-2] and a[m-3];
	}
	if(m==5)
	{
		cout<<a[m] and a[m-1] and a[m-2] and a[m-3] and a[m-4];
	}
	return 0;
}

