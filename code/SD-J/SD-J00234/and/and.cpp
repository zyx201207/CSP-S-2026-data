#include <bits/stdc++.h>
using namespace std;
long long a[200005],n,b[200005],m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==m)
	{
		long long sum=a[1];
		for(int i=2;i<=n;i++)
		{
			sum=(sum&a[i]);
		}
		cout<<sum;
		return 0;
	}
	if(n==1)
	{
		int maxv=1e9;
		for(int i=1;i<=n;i++)
		{
			maxv=max(maxv,a[i]);
		}
		cout<<maxv;
		return 0;
	}
	sort(a+1,a+n+1);
	int j=1;
	for(int i=n;i>=1;i--) 
	{
		if(j==m+1) break;
		else
		{
			b[j]=a[i];
			j++;
		}
	}
	long long sum=b[1];
	for(int i=2;i<=m;i++)
	{
		sum=(sum&b[i]);
	}
	cout<<sum;
	return 0;
}
 


