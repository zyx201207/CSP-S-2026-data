#include<bits/stdc++.h> 
using namespace std;
int a[500010],max1,max2;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,x,m1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	sort(a,a+n+1);
	for(int i=2;i<=n;i++)
	{
		x=a[i];
		max2=1;
		m1=m;
		for(int j=i-1;j>=1;j--)
		{
			if(a[i]>=0)
			{
				if(a[i]-a[j]<=m1)
				{
					m1-=a[i]-a[j];
					max2++;
				}
			}
		}
		max1=max(max1,max2);
	} 
	cout<<max1<<endl;
	return 0;
}
