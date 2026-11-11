#include <bits/stdc++.h>
using namespace std;
int n,m;
long long num=0,sum=1e9;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		num=max(num,a[i]);
		sum=min(sum,a[i]);
	}
	if(n==m)
	{
		for(int i=1;i<=n;i++)
		{
			num=num&a[i];
		}
		cout<<num;
	}
	else if(m==1) cout<<num;
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				long long z=a[i]&a[j];
				sum=max(sum,z);
			}
		}
		cout<<sum;
	}
	else if(m==3)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					sum=max(sum,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<sum;
	}
	else if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=sum) num=num&a[i];
		}
		cout<<num;
	}
	else cout<<0;
 	return 0;
} 
