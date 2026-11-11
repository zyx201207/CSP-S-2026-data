#include<bits/stdc++.h>
using namespace std;
long long a[200007];
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
	sort(a+1,a+n+1);
	while((a[n]&a[n-1])==0)
	{
		n--;
	}
	long long ans=a[n];
	ans=a[n-1];
	for(int i=n;i>=n-m+1;i--)
	{
		ans=(ans&a[i]);
	}
	cout<<ans;
	return 0;
}