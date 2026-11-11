#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int m,n,mmin;
	int mmax;
	cin>>n>>m;
	mmax=m;
	int a[50005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int d[50005];
	int maxx=0;
	for(int i=n;i>=1;i--)
	{
		int x=0;
		m=mmax;
		for(int j=i;j>0;j--)
		{
			int d=a[i]-a[j-1];
			if(m>=d)
			{
				m=m-d;
				x+=1;
			}
		}
		if(x>=maxx)
		{
			maxx=x+1;
		}
	} 
	cout<<maxx;
	return 0;
}
