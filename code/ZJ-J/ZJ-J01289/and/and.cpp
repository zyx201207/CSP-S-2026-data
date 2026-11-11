#include<bits/stdc++.h>
using namespace std;
int a[200020];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int i,k,n,m,f=1,num=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	if(m==1)
	{
		f=0;
		for(i=1;i<=n;i++)
		{
			num=max(num,a[i]);
		}
		cout<<num;
	}
	if(f)
	if(m==n)
	{
		num=a[1];
	for(i=2;i<=n;i++)
	{
		num=num&a[2];
	}	
	cout<<num;
	f=0;
	}
	if(f)
	{
		if(m==2)
		{
			for(i=1;i<=n;i++)
			{
			for(k=i+1;k<=n;k++)
			{
				num=max(num,a[i]&a[k]);
			}	
			}
			cout<<num;
		}
	}
	return 0;
}