#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[20010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		k=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			k=max(a[i],k);
		}
	}
	if(m==n)
	{
		k=a[1];
		for(int i=1;i<=n;i++)
		{
			k=k&a[i];
		}
	}
	cout<<k;
	return 0;
}


