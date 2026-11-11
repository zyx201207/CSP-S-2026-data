#include <bits/stdc++.h>
using namespace std;
int box1[500005],box2[500005],a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal,out","w",stdout);
	int n,m,max1=-1e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		if(a[j]>a[j+1])
		{
			int a1=a[j];
			a[j]=a[j+1];
			a[j+1]=a1;
		}
	}
	for(int i=2;i<=n+1;i++)
	{
		a[i-1]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			int b=a[i]-a[j];
			box1[i]+=b;
			box2[i]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int x=0;
		for(int j=1;j<=i;j++)
		{
			x+=box1[i];
			max1=max(max1,box2[i]);
			if(box1[i]==box1[i+1])
			{
				max1++;
			}
			else if(x>=m)
			{
				max1-=2;
				x-=box1[i];
				break;
			}
		}	
	}
	cout<<max1;
	return 0;
} 
