#include<bits/stdc++.h>
using namespace std;
int n,m,num,ans,p;
int a[10005],b[10005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		num+=a[i];
	}
	num/=n;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=num)
		{
			p=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i==p)
			continue;
		b[i]=a[i]-a[p];
	}
	sort(b+1,b+n+1);
	for(int i=n;i>=1;i--)
	{
		if(i==p)
			continue;
		if(m-b[i]>=0)
		{
			ans++;
			m-=b[i];
		}
	}
	cout<<ans;
 } 
