#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=0,max=0,cnt=0,a[5001],b[5001],d;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	a[n]=100001;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[j]>a[j+1])
			{
				d=a[j+1];
				a[j+1]=a[j];
				a[j]=d; 
			}
		}
	}
	for(int i=0;i<n-1;i++)
	{
		b[i]=a[i+1]-a[i];
	} 
	b[n]=0;
	for(int i=0;i<n-1;i++)
	{
		cnt=0;
		sum=0;
		for(int j=i;j<n-1;j++)
		{
			sum=sum+cnt*b[j]+b[j];
			cnt++;
			if(sum+cnt*b[j+1]+b[j+1]>m)
			{
				break;
			}
		}
		if(max<cnt)
		{
			max=cnt;
		}
	 } 
	cout<<max+1;
	return 0;
}
