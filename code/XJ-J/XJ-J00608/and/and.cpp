#include<bits/stdc++.h>
using namespace std;
int m,n,i,a[1000005],b[1000005],x,y,c[1000005],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
	sort(a+1,a+1+n,greater<int>());
	int max=1,k=1;
	for(i=1;i<=1000004;i++)
	{
		
		if(max<b[i])
		{
			max=b[i];
			c[1]=i;
		}
	}
	if(max==1)
	{
		k=0;
		max=0;
	}
	for(i=1;i<=m-max;i++)
	{
		if(a[i]!=c[1])
		{
			c[++k]=a[i];
		}
	}
	ans=c[1];
	for(i=1;i<=m-max;i++)
	{
		ans=ans&c[i];
	}
	cout<<ans;
	return 0;
}