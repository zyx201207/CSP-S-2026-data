#include<bits/stdc++.h>
using namespace std;
long long n,m,x,a[1010],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(a[1]==a[n])
	{
		cout<<a[1];
		return 0;
	}
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	long long j1=n-1;
	while(a[j1]==a[n])
	{
		j1--;
	}
	if(n-j1+1>=m)
	{
		cout<<a[n];
		return 0;
	}
	ans=a[n];
	for(int i=n-1;i>=n-m+1;i--)ans&=a[i];
	cout<<ans;
	return 0;
}
