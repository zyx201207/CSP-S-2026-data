#include<bits/stdc++.h>
using namespace std;
int a[500001],x[500001],y[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int minn=10000000;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	x[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		x[i]=a[i]-a[i-1];
		minn=min(minn,x[i]);
	}
	y[2]=x[2];
	for(int i=3;i<=n;i++)
	{
		y[i]=y[i-1]+x[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>2;j--)
		{
			if(y[i]-y[j]<=m)
			{
				sum++;
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(x[i]==0)
		{
			sum++
		}
	}
	cout<<sum;

	
	
	  
	  
	  
	  
	return 0;
}

