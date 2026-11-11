#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n,m,a[50006];
cin>>n>>m;
for(int i=0;i<n;i++)
{
cin>>a[i];
}
int sum,max1,m1;
for(int i=n-1;i>=0;i--)
{
m1=m;
sum=0;
	for(int j=i;j>=0;i++)
	{
		if(a[i]-a[i-1]<m1)
		{
		sum++;
		m1-=a[i-1];
		a[i-1]=a[i];
		}
	}
	max1=max(max1,sum);
}
cout<<sum;
return 0;
}
