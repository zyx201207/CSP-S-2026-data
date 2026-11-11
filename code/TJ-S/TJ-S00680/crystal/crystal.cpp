#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans;
int main()
{
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=n;i>0;i--)
	{
		int x=m,ans1=1;
		for(long long j=i-1;j>0;j--)
		{
			if(a[i]-a[j]>x)
			{
				break;
			}
			else
			{
				x-=a[i]-a[j];
				ans1++;
			}
		}
		if(ans<ans1)
		{
			ans=ans1;
		}
	}
	cout<<ans;
	return 0;
 } 
