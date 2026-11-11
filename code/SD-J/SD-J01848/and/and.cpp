#include<bits/stdc++.h>
using namespace std;
long long a[200005]; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	if(n*m<=1000000000)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		long long maxa=0;
		for(int i=n;i>=1;i--)
		{
			long long ans=a[i];
			if(a[i]<maxa)
			{
				cout<<maxa;
				return 0;
			}
			for(int j=1;j<m;j++)
			{
				ans&=a[i-j];
			}
			maxa=max(maxa,ans);
		}
		cout<<maxa;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;
}
