#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[500005],d=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int x=1;x<=n;x++)
	{
		int q=m,z=1;
		for(int i=x-1;i>0;i--)
		{
			if(q>=a[x]-a[i])
			{
				q-=a[x]-a[i];
				z++;
			}
		}
		if(d<z) d=z;
	}
	cout<<d;
	return 0;
}
