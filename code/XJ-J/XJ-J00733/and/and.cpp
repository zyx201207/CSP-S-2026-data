#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		long long maxi=-1;
		for(int i=1;i<=n;i++)
		{
			maxi=max(maxi,a[i]);
		}
		cout<<maxi;
		return 0;
	}
	else if(m==n)
	{
		int sum=a[n];
		for(int i=n-1;i>0;i--)
		{
			sum=sum&a[i];
		}
		cout<<sum;
	}
	else
	{
		long long maxi=-114514;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				maxi=max(maxi,(a[i]&a[j]));
			}
		}
		cout<<maxi;
	}
	return 0;
}
