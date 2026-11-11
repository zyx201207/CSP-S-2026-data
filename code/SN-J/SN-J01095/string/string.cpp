#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i,a[i],c[i],sum=0,num=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[1]>>c[i];
	}
	for(int i=n;i>=0;i--)
	{
		for(int j=1;j<=a[i];i++)
		{
			sum+=c[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];i++)
		{
			num+=c[i];
		}
	}
	if(sum==num)
	{
		cout<<"0";
	}
    return 0;
}
