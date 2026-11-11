#include <bits/stdc++.h>
using namespace std;
int a[1000010];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mmax=-2e9,mmax2=-2e9,mmax3=-2e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mmax=max(mmax,a[i]);
	}
	if(m==1)
	{
		cout<<mmax;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					mmax2=max(mmax2,a[i]&a[j]);
				}
			}
		}
		cout<<mmax2;
	}
	else if(m==n)
	{
		int h;
		for(int i=1;i<=n;i++)
		{
			h=h&a[i];
		}
		cout<<h;
	}
	else
	{
		int o;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=m;i++)
		{
			cout<<a[i]<<endl;
			o=o&a[i];
		}
		cout<<o;
	}
	return 0;
} 
