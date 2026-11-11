#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,a[200005],m;
	cin>>n>>m;
	int max1[m+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		int max=0,x;
		for(int j=1;j<=n;j++)
		{
			if(a[j]>max)
			{
				max=a[i];
				x=j;
			}
		}
		max1[i]=max;
		a[x]=0;
	}
	for(int i=1;i<=m;i++)
	{
		 max1[1]&=max1[i];
	}
	cout<<max1[1];
	
	int lkj;
	lkj=1&2;
	cout<<' '<<lkj;
}