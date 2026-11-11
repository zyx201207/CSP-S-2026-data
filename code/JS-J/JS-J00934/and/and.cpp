#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxn=-1,l;
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
		for(int i=1;i<=n;i++)
		{
			if(a[i]>maxn)
			{
				maxn=a[i];
			}
		}
		cout<<maxn;
	}
	if(m==n)
	{
		maxn=a[1]&a[2];
		for(int i=3;i<=n;i++)
		{
			maxn=maxn&a[i];
		}
		cout<<maxn;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				l=a[i]&a[j];
				if(l>maxn)
				{
					maxn=l;
				}
			}
		}
		cout<<maxn;
	}
	return 0;
}
