#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200005], sum=-1, mx1=-1, mx2=-1, mx3=-1, res=-1;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx1=max(mx1, a[i]);
	}
	if(m==1)
	{
		cout<<mx1;
		return 0;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				mx2=max(mx2, a[i]&a[j]);
			}
		}
		cout<<mx2;
		return 0;
	}
	else if(m==n)
	{
		mx3=a[1];
		for(int i=2;i<=n;i++)
		{
			mx3=mx3&a[i];
		}
		cout<<mx3;
		return 0;
	}
	else
	{
				sort(a+1, a+1+n);
		sum=a[m];
		for(int i=n;i>=n-m+1;i--)
		{
			sum=sum&a[i];
		}

	}
	cout<<sum;
	return 0;
}
