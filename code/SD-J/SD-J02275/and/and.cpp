#include<bits/stdc++.h>
using namespace std;
int a[2005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans=0,flag,y;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(long long i=0;i<n;i++)
	{
		flag=a[i];
		y=i;
		for(long long j=i+1;j<n;j++)
		{
			if(a[j]>flag)
			{
			 	flag=a[j];
			 	y=j;
			}
		}	
		swap(a[i],a[y]);
	}
	ans=a[0];
	for(long long i=1;i<m;i++)
		ans=(ans&a[i]);
	cout<<ans; 
	return 0;
} 
